#include "Http.hpp"
#include "Exception.hpp"

Http::Http() { }
Http::Http(const std::string& path)
{
	ParsingConfig(path);
	// printConfigInfo();
	checkValidConfig();
	SettingHttp();
	runServer();
}
Http::~Http() { }

void Http::SettingHttp()
{
	bool serverOverlap;

	for (std::vector<Server>::iterator it = this->server.begin(); it != this->server.end(); it++) {
		serverOverlap = false;
		for (std::vector<Server>::iterator itt = this->server.begin(); itt != it; itt++) {
			if (it->getPort() == itt->getPort()) {
				serverOverlap = true;
				break;
			}
		}
		if (!serverOverlap) {
			it->setServerSock(socket(AF_INET, SOCK_STREAM, 0));
			if (it->getServerSock() == -1)
				serverFunctionExecuteFailed("socket())");
			struct sockaddr_in serv_adr;

			serv_adr.sin_family = AF_INET;
			serv_adr.sin_addr.s_addr = inet_addr(it->getHost().c_str());
			serv_adr.sin_port = htons(it->getPort());
			it->setSockadr(serv_adr);
			it->setServer();
		}
	}
}

void Http::initializeServer()
{
	bool serverOverlap;

	FD_ZERO(&events);
	for (std::vector<Server>::iterator it = this->server.begin(); it != this->server.end(); it++) {
		serverOverlap = false;
		for (std::vector<Server>::iterator itt = this->server.begin(); itt != it; itt++) {
			if (it->getPort() == itt->getPort()) {
				serverOverlap = true;
				break;
			}
		}
		if (!serverOverlap) {
			if ((listen(it->getServerSock(), LISTEN_SIZE)) == -1)
				serverFunctionExecuteFailed("listen()");
			FD_SET(it->getServerSock(), &events);
			if (fcntl(it->getServerSock(), F_SETFL, O_NONBLOCK) == -1)
				serverFunctionExecuteFailed("fcntl()");
			fd_max = it->getServerSock();
		}
	}
}

void Http::runServer()
{
	int select_ret;
	struct timeval timer;

	initializeServer();
	timer.tv_sec = 1;
	timer.tv_usec = 0;
	while (true) {
		read_event = events;
		err_event = events;
		if ((select_ret = select(fd_max + 1, &read_event, 0, &err_event, &timer)) < 0)
			serverFunctionExecuteFailed("select()");
		clientHandler();
	}
}
