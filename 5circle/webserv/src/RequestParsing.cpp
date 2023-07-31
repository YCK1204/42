#include "Http.hpp"
#include <sstream>

/* line */
std::string Http::getMethod(std::string req_msg)
{
	std::stringstream ss(req_msg);
	std::string ret;

	ss >> ret;
	return spaceTrim(ret);
}

std::string Http::getRoot(std::string req_msg)
{
	std::stringstream ss(req_msg);
	std::string tmp, ret;

	ss >> tmp >> ret;
	ret = spaceTrim(ret);
	return ret;
}

std::string Http::getHTTP(std::string req_msg)
{
	std::stringstream ss(req_msg);
	std::string t, tt, ret;

	ss >> t >> tt >> ret;
	if (ret.find("HTTP") != std::string::npos)
		ret = ret.substr(0, 4);
	return spaceTrim(ret);
}

std::string Http::getHttpVer(std::string req_msg)
{
	std::stringstream ss(req_msg);
	std::string t, tt, ret;
	size_t len = 0;

	ss >> t >> tt >> ret;
	if ((len = ret.find("/")) != std::string::npos)
		ret = ret.substr(len + 1);
	return spaceTrim(ret);
}
/* line */

/* header */
std::string Http::getAddress(std::string req_msg)
{
	std::stringstream ss(req_msg);
	std::string line, ret, cmp;
	size_t len;

	cmp = "Host:";
	while (std::getline(ss, line)) {
		if (line.find(cmp) != std::string::npos) {
			break;
		}
		line.clear();
	}
	len = line.rfind(":");
	if (len == std::string::npos)
		return "11.11.11.11";
	ret = line.substr(5, len);
	if (!ret.compare("localhost"))
		ret = "0.0.0.0";
	return spaceTrim(ret);
}

std::string Http::getPort(std::string req_msg)
{
	std::stringstream ss(req_msg);
	std::string line, ret, cmp;
	size_t len;

	cmp = "Host:";
	while (std::getline(ss, line)) {
		if (line.find(cmp) != std::string::npos)
			break;
		line.clear();
	}
	if (std::strncmp(line.c_str(), cmp.c_str(), cmp.length()))
		return (ret = "65536");
	len = line.rfind(":");
	if (len == std::string::npos)
		return (ret = "65536");
	ret = line.substr(len + 1);
	return spaceTrim(ret);
}

std::string Http::getConnection(std::string req_msg)
{
	std::stringstream ss(req_msg);
	std::string line, ret, cmp;
	size_t len;

	cmp = "Connection:";
	while (std::getline(ss, line)) {
		if (line.find(cmp))
			break;
		line.clear();
	}
	if (line.find(cmp) == std::string::npos)
		return "keep-alive";
	if (!std::strncmp(line.c_str(), cmp.c_str(), cmp.length()) && (len = line.rfind(":")) != std::string::npos)
		ret = line.substr(len + 1);
	return spaceTrim(ret);
}

std::string Http::getCookie(int clnt_sock)
{
	std::string ret, request;

	request = clients[clnt_sock].request;
	std::size_t len = request.find("Cookie:");
	if (len == std::string::npos)
		return "";
	len = request.find(" ", len) + 1;
	std::size_t end = request.find("\r\n", len);
	ret = clients[clnt_sock].request.substr(len, end - len);
	return ret;
}

/* header */

bool Http::isValidAddress(Server server, int addr[4])
{
	std::stringstream tmp;

	if (!server.getHost().compare("0.0.0.0"))
		return true;
	for (int i = 0; i < 3; i++) {
		tmp << addr[i] << ".";
	}
	tmp << addr[3];
	return !server.getHost().compare(tmp.str());
}

void Http::checkRequestMsg(int clnt_sock)
{
	std::string root = clients[clnt_sock].root;
	int port = clients[clnt_sock].port;
	std::string method = clients[clnt_sock].method;
	std::string connection = clients[clnt_sock].connection;
	Server server = getServer(port, root);
	Location location = getLocation(root, server);
	bool methods[3] = { location.getMethods(0), location.getMethods(1), location.getMethods(2) };

	if (err)
		return;
	if (method.compare("GET") && method.compare("POST") && method.compare("DELETE"))
		err = 400;
	else if (!err && ((!methods[GET] && !method.compare("GET")) || (!methods[POST] && !method.compare("POST")) || (!methods[DELETE] && !method.compare("DELETE")))) {
		err = 405;
	}
	if (!err) {
		if (root.length() > MAX_ROOT_LEN)
			err = 414;
		else if (clients[clnt_sock].http.compare("HTTP"))
			err = 501;
		else if (clients[clnt_sock].http_ver.compare("1.1"))
			err = 505;
		else if (!isValidAddress(server, clients[clnt_sock].addr))
			err = 403;
		else if (port == 65536 || server.getPort() != port)
			err = 421;
		else if (connection.compare("keep-alive") && connection.compare("close"))
			err = 400;
	}
}

bool Http::isRegisteredMember(int clnt_sock)
{
	std::string cookie = clients[clnt_sock].cookie;
	std::string session_id = cookie.substr(cookie.find("=") + 1);

	for (std::map<std::string, SessionData>::iterator it = session.begin(); it != session.end(); it++) {
		if (!it->first.compare(session_id)) {
			SessionData data = it->second;

			if (data.port == clients[clnt_sock].port && isMember(data.id))
				return true;
		}
	}
	return false;
}

void Http::getData(int clnt_sock)
{
	std::string req_msg = clients[clnt_sock].request, addr;
	int cnt = 0;
	size_t tmp = 0, len;

	addr = getAddress(req_msg);
	addr = addr.substr(0, addr.find(":"));
	if (!addr.compare("localhost"))
		addr = "127.0.0.1";
	clients[clnt_sock].root = getRoot(req_msg);
	clients[clnt_sock].http = getHTTP(req_msg);
	clients[clnt_sock].method = getMethod(req_msg);
	clients[clnt_sock].http_ver = getHttpVer(req_msg);
	clients[clnt_sock].connection = getConnection(req_msg);
	clients[clnt_sock].port = ft_stoi(getPort(req_msg));
	clients[clnt_sock].cookie = getCookie(clnt_sock);

	for (; (len = addr.find(".", tmp)) != std::string::npos;) {
		cnt++;
		if (cnt > 3) {
			clients[clnt_sock].addr[cnt - 1] = 4242;
			break;
		}
		clients[clnt_sock].addr[cnt - 1] = ft_stoi(addr.substr(tmp, len - tmp));
		tmp = len + 1;
	}
	if (cnt == 3)
		clients[clnt_sock].addr[cnt] = ft_stoi(addr.substr(tmp, len - tmp));
	else
		clients[clnt_sock].addr[cnt] = 4242;
}
