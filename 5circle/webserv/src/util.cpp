#include "Http.hpp"
#include "Location.hpp"

#include <iomanip>
#include <sstream>
#include <string>

int ft_stoi(const std::string& str)
{
	int ret = 0;

	std::stringstream ss(str);
	ss >> ret;
	return (ret);
}

void Http::printConfigInfo()
{
	for (std::vector<Server>::iterator itt = this->server.begin(); itt != this->server.end(); itt++) {
		Server server = *itt;
		std::cout << "server {" << std::endl;
		std::cout << "    listen " << server.getPort() << std::endl;
		if (!server.getServerName().empty())
			std::cout << "    server_name " << server.getServerName() << std::endl;
		if (!server.getRoot().empty())
			std::cout << "    root " << server.getRoot() << std::endl;
		if (server.getClientsBodySize())
			std::cout << "    client_body_size " << server.getClientsBodySize() << std::endl;
		if (!server.getIndex().empty())
			std::cout << "    idnex " << server.getIndex() << std::endl;
		if (!server.getErrPage().empty())
			std::cout << "    error_page " << server.getErrPage() << std::endl;
		if (!server.getIndexRoot().empty())
			std::cout << "    index_root " << server.getIndexRoot() << std::endl;
		std::cout << "    host " << server.getHost() << std::endl;
		std::vector<Location> tmp = server.getLocations();
		for (std::vector<Location>::iterator it = tmp.begin(); it != tmp.end(); it++) {
			std::cout << std::endl;
			std::cout << "    location " + it->getDefaultRoot() + " {" << std::endl;
			std::cout << "        allow_methods ";
			for (int i = 0; i < 3; i++) {
				if (it->getMethods(i)) {
					if (i == GET)
						std::cout << "GET ";
					else if (i == POST)
						std::cout << "POST ";
				}
			}
			std::cout << std::endl;
			if (it->getAutoindex())
				std::cout << "        autoindex on" << std::endl;
			if (!it->getRoot().empty())
				std::cout << "        root " << it->getRoot() << std::endl;
			if (!it->getIndex().empty())
				std::cout << "        index " << it->getIndex() << std::endl;
			if (it->getRet())
				std::cout << "        return " << it->getRedirect() << std::endl;
			if (!it->getCgi().empty())
				std::cout << "        cgi-bin " << it->getCgi() << std::endl;
			std::cout << "    }" << std::endl;
		}
		std::cout << "}\n"
				  << std::endl;
	}
}

std::string Http::getDate()
{
	int month;
	char buffer[80];
	ssize_t monthPos;
	struct tm* selTimeInfo;
	time_t rawTime, selTime;
	std::string dateHeader, monthName;
	const char* monthNames[] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};

	std::time(&rawTime);
	selTime = rawTime + (9 * 3600);
	selTimeInfo = std::gmtime(&selTime);
	std::strftime(buffer, sizeof(buffer), "Date: %a, %d %b %Y %H:%M:%S SEL", selTimeInfo);
	dateHeader = static_cast<std::string>(buffer);
	month = selTimeInfo->tm_mon;
	monthName = monthNames[month];
	monthPos = dateHeader.find("MMM");
	if (static_cast<size_t>(monthPos) != std::string::npos)
		dateHeader.replace(monthPos, 3, monthName);
	return dateHeader;
}

void Http::addFdSet(int clnt_sock, fd_set& event)
{
	FD_SET(clnt_sock, &event);
	if (clnt_sock > fd_max)
		fd_max = clnt_sock;
}

void Http::clearFdSet(int clnt_sock, fd_set& event)
{
	FD_CLR(clnt_sock, &event);
	if (clnt_sock == fd_max)
		fd_max--;
	close(clnt_sock);
}

std::string Http::spaceTrim(std::string str)
{
	int start, end;
	for (start = 0; str[start]; start++) {
		if (str[start] != ' ')
			break;
	}
	for (end = str.length() - 1; end > 0; end--) {
		if (str[end] != ' ')
			break;
	}
	return str.substr(start, end - start + 1);
}

bool Http::checkValidateAddress(int addr[4])
{
	int validAddr[4][4], err = 1;

	for (int i = 0; i < 4; i++) {
		if (addr[i] > 255 || addr[i] < 0) {
			return true;
		}
	}
	validAddr[0][0] = 0;
	validAddr[0][1] = 0;
	validAddr[0][2] = 0;
	validAddr[0][3] = 0;

	validAddr[1][0] = 127;
	validAddr[1][1] = 0;
	validAddr[1][2] = 0;
	validAddr[1][3] = 1;

	validAddr[2][0] = 10;
	validAddr[2][1] = 31;
	validAddr[2][2] = 2;
	validAddr[2][3] = 4;

	validAddr[3][0] = 10;
	validAddr[3][1] = 19;
	validAddr[3][2] = 200;
	validAddr[3][3] = 153;

	for (int i = 0; i < 4; i++) {
		if (addr[0] == validAddr[i][0] && addr[1] == validAddr[i][1] && addr[2] == validAddr[i][2] && addr[3] == validAddr[i][3])
			err = 0;
	}
	if (err) {
		return true;
	}
	return false;
}

Server Http::getServer(int port, std::string root)
{
	bool f = false;
	std::vector<Server>::iterator it;

	for (it = this->server.begin(); it != this->server.end(); it++) {
		Server& server = *it;
		if (server.getPort() == port) {
			std::vector<Location> location = server.getLocations();
			for (std::vector<Location>::iterator it = location.begin(); it != location.end(); it++) {
				if (!it->getDefaultRoot().compare(root)) {
					f = true;
					break;
				}
			}
		}

		if (f)
			break;
	}
	for (it = this->server.begin(); it != this->server.end() && port != it->getPort(); it++)
		if (it == this->server.end())
			return *(this->server.begin());
	return *it;
}

Location Http::getLocation(std::string root, Server server)
{
	std::vector<Location> locations = server.getLocations();
	std::vector<Location>::iterator it;

	for (it = locations.begin(); it != locations.end(); it++) {
		Location& location = *it;
		if (!location.getDefaultRoot().compare(root))
			break;
	}

	if (it == locations.end()) {
		return *(locations.begin());
	}
	return *it;
}

std::string Http::getIndexRoot(Server server, Location location)
{
	std::string ret;

	if (location.getRoot().empty())
		ret += server.getRoot();
	else
		ret += location.getRoot();
	if (location.getIndex().empty())
		ret += server.getIndex();
	else
		ret += location.getIndex();
	return ret;
}

bool Http::isDir(std::string dir_root)
{
	DIR* dir;
	bool ret = false;

	dir = opendir(dir_root.c_str());
	if (dir) {
		ret = true;
		closedir(dir);
	}
	return ret;
}

bool Http::isFile(std::string file_root)
{
	std::ifstream file;
	bool ret = false;

	file.open(file_root.c_str());
	if (file.is_open())
		ret = true;
	file.close();
	return ret;
}

std::string Http::decoding(const std::string& encodedString)
{
	std::string decodedString;
	std::istringstream iss(encodedString);
	char c;
	int value;

	while (iss.get(c)) {
		if (c == '%') {
			if (iss >> std::hex >> value) {
				decodedString += static_cast<char>(value);
			}
		} else if (c == '+') {
			decodedString += ' ';
		} else {
			decodedString += c;
		}
	}

	return decodedString;
}

char* Http::ft_strrstr(int clnt_sock, char* str, int size)
{
	std::size_t needle_size = std::strlen(str);

	for (; size >= 0; size--) {
		if (!strncmp(&(clients[clnt_sock].img.buf[size]), str, needle_size))
			return &clients[clnt_sock].img.buf[size];
	}
	return NULL;
}

std::string Http::getPassword(std::string body)
{
	return body.substr(body.rfind("=") + 1);
}

std::string Http::getId(std::string body)
{
	std::size_t len = body.find("&");
	return body.substr(len + 4, body.find("&", len + 1) - len - 4);
}

bool Http::checkAccessControl(int clnt_sock)
{
	bool ret = false;
	bool is_logged = !clients[clnt_sock].cookie.empty();
	std::string root = clients[clnt_sock].root;

	if (!is_logged) {
		if (!root.compare("/cgi/calculator")) {
			ret = true;
		} else if (!root.compare("/upload")) {
			ret = true;
		} else if (!root.compare("/sign_out"))
			ret = true;
	} else {
		if (!root.compare("/sign_in")) {
			ret = true;
		} else if (!root.compare("/sign_up")) {
			ret = true;
		}
	}
	return ret;
}

std::string Http::readFile(std::string file_path)
{
	std::string total, line;
	std::ifstream file;

	file.open(file_path.c_str());
	if (file.is_open()) {
		while (std::getline(file, line)) {
			total += line;
			line.clear();
			if (!file.eof())
				total += '\n';
		}
	} else {
		err = 404;
	}
	file.close();
	return total;
}
