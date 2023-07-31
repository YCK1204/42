#include "Http.hpp"
#include <cstdio>
#include <iostream>
#include <string>

std::string Http::getBodyMethod(int clnt_sock)
{
	size_t i, next_newline, tmp;

	if (!std::strncmp("_method", clients[clnt_sock].body_request.c_str(), 7)) {
		i = clients[clnt_sock].body_request.find("=");
		next_newline = clients[clnt_sock].body_request.find("&");
		if (i == std::string::npos) {
			err = 400;
			return "";
		}
		i++;
		if (next_newline == std::string::npos)
			next_newline = i + 6;
	} else {
		i = clients[clnt_sock].body_request.find("name=\"_method\"");
		next_newline = clients[clnt_sock].body_request.find("\r\n\r\n", i);
		tmp = clients[clnt_sock].body_request.find("------WebKitFormBoundary", next_newline);
		if (i == std::string::npos || next_newline == std::string::npos || tmp == std::string::npos) {
			err = 400;
			return "";
		}
		next_newline += 4;
		return clients[clnt_sock].body_request.substr(next_newline, tmp - (next_newline + 2));
	}
	return clients[clnt_sock].body_request.substr(i, next_newline - i);
}

void Http::postHandler(int clnt_sock, std::size_t len)
{
	std::size_t length = clients[clnt_sock].request.find("Content-Length:");

	if (length == std::string::npos) {
		err = 400;
		writeResponse(clnt_sock);
		disconnectClient(clnt_sock);
		return;
	}

	clients[clnt_sock].body_size = clients[clnt_sock].str_len - (len + 4);
	if (clients[clnt_sock].body_size == static_cast<std::size_t>(ft_stoi(clients[clnt_sock].request.substr(length + 16)))) {
		clients[clnt_sock].body_request.append(clients[clnt_sock].request.substr(len + 4));
		clients[clnt_sock].body_method = getBodyMethod(clnt_sock);
		if (clients[clnt_sock].body_request.find("------WebKitFormBoundary") == std::string::npos) {
			clients[clnt_sock].body_request = decoding(clients[clnt_sock].body_request);
		} else {
			parsingFormData(clnt_sock);
		}
		writeResponse(clnt_sock);
	} else {
		clients[clnt_sock].body_request.clear();
	}
}

void Http::parsingFormData(int clnt_sock)
{
	if (!clients[clnt_sock].body_method.compare(("file_upload")))
		parsingImageData(clnt_sock);
	else if (!clients[clnt_sock].body_method.compare("cgi-calculator"))
		parsingCalculator(clnt_sock);
}

std::string Http::getFileName(int clnt_sock)
{
	size_t i, next_quote;
	std::string info = "Content-Disposition: form-data; name=\"file\"; filename=\"";

	i = clients[clnt_sock].body_request.find(info);
	if (i == std::string::npos) {
		err = 400;
		return "";
	}
	i += info.length();
	next_quote = clients[clnt_sock].body_request.find("\"", i);
	if (next_quote == std::string::npos) {
		err = 400;
		return "";
	}
	return clients[clnt_sock].body_request.substr(i, next_quote - i);
}

void Http::parsingCalculator(int clnt_sock)
{
	std::string body = clients[clnt_sock].body_request;
	std::size_t len = body.find("Content-Disposition: form-data; name=\"display\"");
	std::size_t start, end;

	if (len == std::string::npos) {
		err = 400;
		return;
	}
	len = body.find("\r\n\r\n", len);
	if (len == std::string::npos) {
		err = 400;
		return;
	}
	len += 4;
	start = len;
	end = body.find("\r\n", start);
	clients[clnt_sock].cal.display = body.substr(start, end - start);
}

void Http::parsingImageData(int clnt_sock)
{
	char* start;
	char* end;

	start = std::strstr(clients[clnt_sock].img.buf, "Content-Disposition: form-data; name=\"file\"; filename=\"");
	if (start == NULL) {
		err = 400;
		return;
	}
	start = std::strstr(start, "\r\n\r\n");
	if (start == NULL) {
		err = 400;
		return;
	}
	for (int i = 0; i < 4; i++)
		start++;
	std::string tmp = "\r\n------WebKitFormBoundary";
	end = ft_strrstr(clnt_sock, (char*)tmp.c_str(), clients[clnt_sock].str_len);
	if (end == NULL) {
		err = 400;
		return;
	}
	int k = end - start;
	clients[clnt_sock].img.binary_request = new char[k];
	for (int i = 0; i < k; i++) {
		clients[clnt_sock].img.binary_request[i] = start[i];
	}
	clients[clnt_sock].img.image_size = k;
}
