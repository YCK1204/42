#include "Exception.hpp"
#include "Http.hpp"
#include "Server.hpp"

Server& Server::makeServer(std::ifstream& file)
{
	Location tmp;
	std::string line, cmd;
	int types[7] = {}, t = 0;

	location.clear();
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		std::stringstream ss(line);
		ss >> cmd;
		if (!cmd.compare("}") && ++t)
			break;
		if (cmd.compare("location")) {
			setServerOption(ss, cmd, types);
		} else {
			location.push_back(tmp.makeLocation(file, ss));
		}
	}
	checkValidServerOption(types);
	if (t != 1) {
		FT_THROW("server is not finished \"}\"", NotValidConfigFileException());
	}
	return *this;
}

std::string Server::buildServerOption(std::stringstream& ss)
{
	std::string ret, tmp;

	ss >> ret >> tmp;
	if (!tmp.empty()) {
		FT_THROW(tmp + "server option error", NotValidConfigFileException());
	}
	return ret;
}

void Server::setServerOption(std::stringstream& ss, std::string cmd, int types[7])
{
	if (!cmd.compare("listen") && ++types[LISTEN]) {
		_port = ft_stoi(buildServerOption(ss));
	} else if (!cmd.compare("error_page") && ++types[ERROR_PAGE]) {
		_error_page = buildServerOption(ss);
	} else if (!cmd.compare("host") && ++types[HOST]) {
		_host = buildServerOption(ss);
	} else if (!cmd.compare("client_body_size") && ++types[BODY_SIZE]) {
		_client_body_size = ft_stoi(buildServerOption(ss));
	} else if (!cmd.compare("index") && ++types[S_INDEX]) {
		_index = buildServerOption(ss);
	} else if (!cmd.compare("root") && ++types[S_ROOT]) {
		_root = buildServerOption(ss);
	} else if (!cmd.compare("server_name") && ++types[SERVER_NAME]) {
		_server_name = buildServerOption(ss);
	} else {
		FT_THROW(cmd + " server option error", NotValidConfigFileException());
	}
}

void Server::checkValidServerOption(int types[7])
{
	std::string msg, reason;

	if (types[LISTEN] != 1) {
		msg = "listen";
		reason = "should only appear once";
	} else if (types[ERROR_PAGE] != 1) {
		msg = "error_page";
		reason = "should only appear once";
	} else if (types[HOST] != 1) {
		msg = "host";
		reason = "should only appear once";
	} else if (types[BODY_SIZE] != 1) {
		msg = "client body size";
		reason = "should only appear once";
	} else if (types[S_INDEX] > 1) {
		msg = "client body size";
		reason = "must appear at most once";
	} else if (types[S_ROOT] > 1) {
		msg = "server root";
		reason = "must appear at most once";
	} else if (types[SERVER_NAME] > 1) {
		msg = "server name";
		reason = "must appear at most once";
	}
	if (!msg.empty()) {
		FT_THROW(msg + " " + reason, NotValidConfigFileException());
	}
}
