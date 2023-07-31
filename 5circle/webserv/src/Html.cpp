#include "Http.hpp"
#include <sstream>
#include <string>

std::string Http::buildHtml(const std::string msg)
{
	std::string ret;

	ret += "<!DOCTYPE html>\n"
		   "<html>\n"
		   "<head>\n"
		   "    <meta charset=\"UTF-8\">\n"
		   "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=chrome\">\n"
		   "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
		   "    <title>Document</title>\n"
		   "</head>\n"
		   "<body>\n";
	ret += "    " + msg;
	ret += "</body>\n"
		   "</html>\r\n\r\n";
	return ret;
}

std::string Http::buildErrorHtml(const int status, Server server)
{
	std::string ret;
	std::stringstream ss;

	if (status == 404) {
		std::string file_path;

		file_path = server.getRoot() + server.getErrPage().substr(1);
		ret = readFile(file_path);
		return buildHtml(ret);
	}
	ss << "<h1>" << err << " " << mime.getStatus(err) << "</h1><br><a href=\"/\">Main Page</a>\n";
	ret = buildHtml(ss.str());
	return ret;
}

std::string Http::buildErrorMsg(int clnt_sock)
{
	std::stringstream ss;

	ss << "HTTP/1.1 " << err << " " << mime.getStatus(err) << "\r\n";
	ss << "Connection: keep-alive\r\n";
	ss << getDate() << "\r\n";
	ss << "Content-type: text/html\r\n";
	if (!clients[clnt_sock].redirect.empty())
		ss << "Location: " + clients[clnt_sock].redirect + "\r\n";
	ss << "\r\n";

	return ss.str();
}
