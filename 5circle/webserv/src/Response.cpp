#include "Http.hpp"
#include <fstream>

void Http::setRedirect(int clnt_sock)
{
	std::string root = clients[clnt_sock].root;
	if (checkAccessControl(clnt_sock)) {
		clients[clnt_sock].redirect = "/";
		status = 302;
	}
	checkCookie(clnt_sock);
}

std::string Http::getMsg(int clnt_sock, int length)
{
	std::string file_path, req_msg = clients[clnt_sock].request;
	Server server = getServer(clients[clnt_sock].port, clients[clnt_sock].root);
	Location location = getLocation(clients[clnt_sock].root, server);
	struct stat file_stat;
	bool at = false;

	if (location.getRet() && !location.getAutoindex())
		status = 302;
	else if (clients[clnt_sock].at && clients[clnt_sock].root[clients[clnt_sock].root.length() - 1] != '/') {
		clients[clnt_sock].root += "/";
		status = 302;
		at = true;
	}
	setRedirect(clnt_sock);

	std::stringstream ss;

	ss << "HTTP/1.1 " << status << " " << mime.getStatus(status) << "\r\n";
	ss << "Accept-language: ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7\r\n";
	ss << "Cache-Control:no-cache=\"Set-Cookie\"\r\n";
	ss << "Connection: " << clients[clnt_sock].connection << "\r\n";
	ss << "Content-Length: " << length << "\r\n";
	ss << "Content-Type: " << mime.getType(clients[clnt_sock].file_extension) << "; charset=utf-8\r\n";
	ss << getDate() << "\r\n";

	if (!clients[clnt_sock].connection.compare("keep-alive"))
		ss << "keep-alive: timeout=" << TIMEOUT << ", max=" << REQUEST_CNT << "\r\n";

	file_path = getIndexRoot(server, location);
	if (stat(file_path.c_str(), &file_stat) >= 0)
		ss << "Last-Modified: " << formatTime(file_stat.st_mtime) << "\r\n";

	if (location.getRet() && !location.getAutoindex())
		ss << "Location: " << location.getRedirect() << "\r\n";
	else if (at)
		ss << "Location: " << clients[clnt_sock].root << "\r\n";
	else if (!clients[clnt_sock].redirect.empty())
		ss << "Location: " + clients[clnt_sock].redirect + "\r\n";

	if (clients[clnt_sock].set_cookie)
		ss << createCookie(clnt_sock);
	else if (clients[clnt_sock].delete_cookie)
		ss << deleteCookie();
	ss << "Server: " << server.getServerName() << "\r\n\r\n";
	return ss.str();
}

std::string Http::getAutoindex(int clnt_sock, Server& server)
{
	std::string ret, root, line;
	std::ifstream file;

	root = server.getRoot();
	root += clients[clnt_sock].root;
	if (isDir(root)) {
		clients[clnt_sock].at = true;
		ret = buildAutoindex(server.getRoot(), clients[clnt_sock].root);
	} else {
		ret = readFile(root);
	}
	return ret;
}

std::string Http::buildGetResponse(int clnt_sock)
{
	std::string root, line, ret;
	std::ifstream file;
	Server server = getServer(clients[clnt_sock].port, clients[clnt_sock].root);
	Location location = getLocation(clients[clnt_sock].root, server);

	if (!clients[clnt_sock].root.compare(location.getDefaultRoot())) {
		if (location.getRet())
			return "";
		root = getIndexRoot(server, location);

		if (isFile(root)) {
			ret = readFile(root);
			size_t len = root.rfind(".");
			if (len != std::string::npos)
				clients[clnt_sock].file_extension = root.substr(len + 1);
		} else {
			err = 500;
		}
	} else {
		err = 404;
	}
	return ret;
}

int Http::isAutoindex(int clnt_sock)
{
	std::vector<Server> server = this->server;
	std::size_t i, j;

	for (i = 0; i < server.size(); i++) {
		if (server[i].getPort() == clients[clnt_sock].port) {
			std::vector<Location> locations(server[i].getLocations());
			for (j = 0; j < locations.size(); j++) {
				std::string location_root = locations[j].getDefaultRoot();
				if (!std::strncmp(location_root.c_str(), clients[clnt_sock].root.c_str(), location_root.length())) {
					if (locations[j].getAutoindex()) {
						return i;
					}
				}
			}
		}
	}

	return server.size();
}

std::string Http::getContent(int clnt_sock)
{
	std::string ret;
	int server_idx = isAutoindex(clnt_sock);

	clients[clnt_sock].file_extension = "html";
	if (server_idx != static_cast<int>(server.size()))
		ret = getAutoindex(clnt_sock, server[server_idx]);
	else
		ret = buildGetResponse(clnt_sock);

	if (err)
		return buildErrorHtml(err, getServer(clients[clnt_sock].port, clients[clnt_sock].root));
	return ret;
}

std::string Http::receiveFile(int clnt_sock)
{
	std::ofstream file;
	std::string ret, file_name;

	file_name = getFileName(clnt_sock);
	file.open(("./docs/received_file/" + file_name).c_str(), std::ofstream::trunc | std::ios::binary);
	if (file.is_open()) {
		for (std::size_t i = 0; i < clients[clnt_sock].img.image_size; i++) {
			file << clients[clnt_sock].img.binary_request[i];
		}
	} else {
		err = 400;
		ret = buildErrorHtml(400, getServer(clients[clnt_sock].port, clients[clnt_sock].root));
	}
	file.close();
	return ret;
}

std::pair<std::string, std::string> Http::getPostReseponse(int clnt_sock)
{
	std::string body = clients[clnt_sock].body_request;
	std::string method = clients[clnt_sock].body_method;
	std::pair<std::string, std::string> ret;
	Server server = getServer(clients[clnt_sock].port, clients[clnt_sock].root);

	clients[clnt_sock].file_extension = "html";
	if (clients[clnt_sock].body_size > static_cast<std::size_t>(server.getClientsBodySize())) {
		err = 400;
		ret.first = buildErrorMsg(clnt_sock);
		ret.second = buildErrorHtml(400, server);
		return ret;
	}

	if (!method.compare("sign_up")) {
		ret.second = SignUp(body, clnt_sock);
	} else if (!method.compare("sign_in")) {
		ret.second = SignIn(body, clnt_sock);
	} else if (!method.compare("file_upload")) {
		ret.second = receiveFile(clnt_sock);
	} else if (!method.compare("cgi-calculator")) {
		ret.second = cgiCalculator(clnt_sock);
	} 

	if (err)
		ret.first = buildErrorMsg(clnt_sock);
	else
		ret.first = getMsg(clnt_sock, ret.second.length());
	return ret;
}

std::pair<std::string, std::string> Http::buildErrReseponse(int clnt_sock)
{
	std::pair<std::string, std::string> ret;

	Server server = getServer(clients[clnt_sock].port, clients[clnt_sock].root);
	ret.first = buildErrorMsg(clnt_sock);
	ret.second = buildErrorHtml(err, server);
	return ret;
}

std::pair<std::string, std::string> Http::getResponse(int clnt_sock)
{
	std::pair<std::string, std::string> ret;

	getData(clnt_sock);
	checkRequestMsg(clnt_sock);

	if (clients[clnt_sock].request_cnt >= REQUEST_CNT)
		err = 429;

	if (err) {
		ret = buildErrReseponse(clnt_sock);
	} else {
		if (!clients[clnt_sock].method.compare("POST")) {
			ret = getPostReseponse(clnt_sock);
		} else if (!clients[clnt_sock].method.compare("DELETE")) {
			ret.second = SignOut(clients[clnt_sock].body_request, , clnt_sock);
			ret.first = getMsg(clnt_sock, ret.second.length());
		} else {
			ret.second = getContent(clnt_sock);

			if (err) {
				ret = buildErrReseponse(clnt_sock);
			} else {
				ret.first = getMsg(clnt_sock, ret.second.length());
			}
		}
	}
	return ret;
}
