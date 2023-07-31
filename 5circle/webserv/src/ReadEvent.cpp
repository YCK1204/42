#include "Exception.hpp"
#include "Http.hpp"

void Http::eventReadHandler(int clnt_sock)
{
	bool t = false;

	for (std::vector<Server>::iterator it = this->server.begin(); it != this->server.end(); it++) {
		if (clnt_sock == it->getServerSock()) {
			clientAccept(it->getServerSock());
			t = true;
			break;
		}
	}
	if (!t && clients.find(clnt_sock) != clients.end()) {
		readRequestMsg(clnt_sock);
	}
}

void Http::clientAccept(int serv_sock)
{
	int clnt_sk;
	struct sockaddr_in clnt_adr;
	socklen_t clnt_adr_size;

	clnt_adr_size = sizeof(clnt_adr);
	if ((clnt_sk = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_size)) == -1) {
		FT_THROW("accept() accept function error", SettingHttpException());
	}

	clientInit(clnt_sk);
	clients[clnt_sk].request_cnt = 0;
	addFdSet(clnt_sk, events);
	fcntl(clnt_sk, F_SETFL, O_NONBLOCK);
	std::cout << "client connected : " << clnt_sk << std::endl;
}

void Http::readRequestMsg(int clnt_sock)
{
	ssize_t n;
	std::size_t len;
	char buf[BUF_SIZE + 1];
	char* tmp;

	n = read(clnt_sock, buf, BUF_SIZE);
	if (n <= 0) {
		disconnectClient(clnt_sock);
	} else if (n) {
		buf[n] = '\0';
		clients[clnt_sock].request += static_cast<std::string>(buf);

		tmp = new char[clients[clnt_sock].str_len + 1];
		if (tmp == NULL)
			FT_THROW("Error: malloc()", SettingHttpException());
		for (std::size_t i = 0; i < clients[clnt_sock].str_len; i++) {
			tmp[i] = clients[clnt_sock].img.buf[i];
		}
		tmp[clients[clnt_sock].str_len] = '\0';
		delete[] clients[clnt_sock].img.buf;
		clients[clnt_sock].str_len += n;
		clients[clnt_sock].img.buf = new char[clients[clnt_sock].str_len + 1];

		if (clients[clnt_sock].img.buf == NULL)
			FT_THROW("Error: malloc()", SettingHttpException());
		for (std::size_t i = 0; i < clients[clnt_sock].str_len - n; i++)
			clients[clnt_sock].img.buf[i] = tmp[i];
		for (ssize_t i = 0; i < n; i++)
			clients[clnt_sock].img.buf[i + (clients[clnt_sock].str_len - n)] = buf[i];
		clients[clnt_sock].img.buf[clients[clnt_sock].str_len] = '\0';

		clients[clnt_sock].last_active_times = std::time(NULL);
		len = clients[clnt_sock].request.find("\r\n\r\n");
		if (len != std::string::npos) {
			if (!std::strncmp(clients[clnt_sock].request.c_str(), "POST", 4))
				postHandler(clnt_sock, len);
			else
				writeResponse(clnt_sock);
		}
		delete[] tmp;
	}
}
