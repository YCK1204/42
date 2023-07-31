#include "Exception.hpp"
#include "Http.hpp"

void Http::decideConnecting(int clnt_sock)
{
	if (++clients[clnt_sock].request_cnt >= REQUEST_CNT) {
		disconnectClient(clnt_sock);
	} else {
		if (!clients[clnt_sock].connection.compare("close")) {
			disconnectClient(clnt_sock);
		} else {
			clientInit(clnt_sock);
		}
	}
}

void Http::writeResponse(int clnt_sock)
{
	std::pair<std::string, std::string> response;
	ssize_t n;

	err = 0;
	status = 200;
	if (!clients[clnt_sock].request.empty()) {
		response = getResponse(clnt_sock);
		if ((n = (write(clnt_sock, response.first.c_str(), response.first.length()))) == -1)
			std::cerr << ORANGE "Error : write error (response msg)" CLEAR << std::endl;
		else if ((n = (write(clnt_sock, response.second.c_str(), response.second.length()))) == -1)
			std::cerr << ORANGE "Error : write error (response content)" CLEAR << std::endl;

		if (clients[clnt_sock].img.buf)
			delete[] clients[clnt_sock].img.buf;
		clients[clnt_sock].img.buf = NULL;
		if (clients[clnt_sock].img.binary_request)
			delete[] clients[clnt_sock].img.binary_request;
		clients[clnt_sock].img.binary_request = NULL;
		if (n != -1) {
			printLog(clnt_sock);
			if (!err) {
				checkSession(clnt_sock);
				decideConnecting(clnt_sock);
			} else {
				disconnectClient(clnt_sock);
			}
		} else {
			disconnectClient(clnt_sock);
		}
	}
}
