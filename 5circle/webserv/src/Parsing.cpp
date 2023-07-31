#include <sstream>

#include "Exception.hpp"
#include "Http.hpp"
#include "Location.hpp"

void Http::checkEmptyFile(const std::string& path)
{
	std::ifstream file;
	std::string line;

	file.open(path.c_str());
	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (line.empty())
				continue;
			else if (!line.compare("server {"))
				break;
			else
				FT_THROW(line + "server is not started \"server {\"", NotValidConfigFileException());
		}
	} else
		FT_THROW(path + " file not found", NoSuchFileException());
	if (line.empty())
		FT_THROW(path + " file is empty", EmptyFileException());
	file.close();
}

void Http::ParsingConfig(const std::string& path)
{
	Server tmp;
	std::ifstream file;
	std::string line, cmd, t;

	checkEmptyFile(path);
	file.open(path.c_str());
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		std::stringstream ss(line);
		ss >> cmd;
		if (cmd.compare("server"))
			FT_THROW(line + " server is not started \"server {\"", NotValidConfigFileException());
		ss >> cmd;
		if (cmd.compare("{"))
			FT_THROW(line + "server is not started \"server {\"", NotValidConfigFileException());
		ss >> t;
		if (!t.empty())
			FT_THROW(line + " server is not started \"server {\"", NotValidConfigFileException());
		this->server.push_back(tmp.makeServer(file));
	}
	file.close();
}

void Http::checkValidAddr(const std::string& host)
{
	size_t len;
	size_t temp = 0;
	int cnt = 0, t, addr[4];

	for (; (len = host.find(".", temp)) != std::string::npos;) {
		cnt++;
		const std::string port = host.substr(temp, len - temp);
		try {
			t = ft_stoi(port);
		} catch (const std::invalid_argument& e) {
			std::stringstream ss;
			ss << port << " is not valid port number";
			FT_THROW(ss.str(), NotValidConfigFileException());
		}
		if (cnt > 3)
			FT_THROW(host + " is not valid server address (xxx.xxx.xxx.xxx)", NotValidConfigFileException());
		addr[cnt - 1] = t;
		temp = len + 1;
	}
	std::string port = host.substr(temp, len - temp);
	try {
		t = ft_stoi(port);
	} catch (const std::invalid_argument& e) {
		std::stringstream ss;
		ss << port << " is not valid port number";
		FT_THROW(ss.str(), NotValidConfigFileException());
	}
	addr[cnt] = t;
	if (cnt != 3)
		FT_THROW(host + " is not valid server address(xxx.xxx.xxx.xxx)", NotValidConfigFileException());
	if (checkValidateAddress(addr))
		FT_THROW(host + " can not use server address", NotValidConfigFileException());
}

void Http::checkValidConfig()
{
	for (std::vector<Server>::iterator it = server.begin(); it != server.end(); it++) {
		Server& server = *it;
		if (server.getPort() > 65535) {
			FT_THROW("listen can not use server port", NotValidConfigFileException());
		}
		checkValidAddr(server.getHost());
		for (std::size_t i = 0; i < server.getLocations().size(); i++) {
			for (std::size_t j = i; j < server.getLocations().size(); j++) {
				if (i == j)
					continue;
				if (!server.getLocations()[i].getDefaultRoot().compare(server.getLocations()[j].getDefaultRoot())) {
					FT_THROW(server.getLocations()[i].getDefaultRoot() + " overlap location block", NotValidConfigFileException());
				}
			}
		}
	}
}
