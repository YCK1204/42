#include "Exception.hpp"
#include "Http.hpp"
#include <sys/types.h>

void Http::clientInit(int clnt_sock)
{
	clients[clnt_sock].at = false;
	clients[clnt_sock].set_cookie = false;
	clients[clnt_sock].delete_cookie = false;
	clients[clnt_sock].str_len = 0;
	clients[clnt_sock].body_size = 0;
	clients[clnt_sock].img.image_size = 0;
	clients[clnt_sock].img.binary_request = NULL;
	clients[clnt_sock].root = "";
	clients[clnt_sock].cookie = "";
	clients[clnt_sock].method = "";
	clients[clnt_sock].request = "";
	clients[clnt_sock].redirect = "";
	clients[clnt_sock].http_ver = "";
	clients[clnt_sock].body_method = "";
	clients[clnt_sock].body_request = "";
	clients[clnt_sock].file_extension = "";
	clients[clnt_sock].connection = "keep-alive";
	clients[clnt_sock].last_active_times = std::time(NULL);

	clients[clnt_sock].img.buf = new char[BUF_SIZE + 1];
	if (clients[clnt_sock].img.buf == NULL)
		FT_THROW("Error: malloc()", SettingHttpException());
}

void Http::eventErrHandler(int clnt_sock)
{
	Server server;

	for (std::vector<Server>::iterator it = this->server.begin(); it != this->server.end(); it++) {
		if (clnt_sock == it->getServerSock())
			FT_THROW("socket server socket error", SettingHttpException());
	}
	std::cerr << "client socket error" << std::endl;
	disconnectClient(clnt_sock);
}

void Http::disconnectClient(int clnt_sock)
{
	std::cout << "client disconnected : " << clnt_sock << std::endl;
	if (clients[clnt_sock].img.binary_request)
		delete[] clients[clnt_sock].img.binary_request;
	if (clients[clnt_sock].img.buf)
		delete[] clients[clnt_sock].img.buf;
	clients.erase(clnt_sock);
	clearFdSet(clnt_sock, events);
}

void Http::clientHandler()
{
	for (int i = 0; i <= fd_max; i++) {
		if (FD_ISSET(i, &err_event))
			eventErrHandler(i);
		else if (FD_ISSET(i, &read_event)) {
			eventReadHandler(i);
		}
	}
	for (std::map<int, ClientData>::iterator it = clients.begin(); it != clients.end(); it++) {
		if ((std::time(NULL) - it->second.last_active_times) > TIMEOUT) {
			disconnectClient(it->first);
			break;
		}
	}
}

void Http::printLog(int clnt_sock)
{
	if (err) {
		std::cout << RED << "Response to client : " << clnt_sock << ", status=[" << err << "], method=[" << clients[clnt_sock].method << "], URI=" << clients[clnt_sock].root << CLEAR << std::endl;
	} else {
		const char* const color = status >= 300 ? LIME : status <= 200 ? SKY_BLUE
																	   : YELLOW;
		std::cout << color << "Response to client : " << clnt_sock << ", status=[" << status << "], method=[" << clients[clnt_sock].method << "], URI=" << clients[clnt_sock].root << CLEAR << std::endl;
	}
}
