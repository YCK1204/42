#include "Http.hpp"

std::string Http::createCookie(int clnt_sock)
{
	std::string file_path = "./docs/cgi/create_session.php";
	std::string session_id = runCgi(SESSION, file_path, "", PHP_PATH);

	session[session_id] = makeSession(clnt_sock);
	clients[clnt_sock].redirect = "/";
	return "Set-Cookie: SessionId=" + session_id + "; Max-Age=1800; Path=/; HttpOnly;\r\n";
}

void Http::redirectClient(int clnt_sock, bool set_cookie)
{
	if (set_cookie) {
		clients[clnt_sock].set_cookie = true;
	} else {
		clients[clnt_sock].delete_cookie = true;
	}
	clients[clnt_sock].redirect = "/";
	status = 302;
}

void Http::checkCookie(int clnt_sock)
{
	std::string cookie = clients[clnt_sock].cookie;

	if (!cookie.empty()) {
		std::string session_id = cookie.substr(cookie.find("=") + 1);
		bool f = false;

		for (std::map<std::string, SessionData>::iterator it = session.begin(); it != session.end(); it++) {
			if (!session_id.compare(it->first))
				f = true;
		}

		if (!f) {
			redirectClient(clnt_sock, f);
		}
	}
}

std::string Http::deleteCookie()
{
	return "Set-Cookie: SessionId=\"\"; Max-Age=0;\r\n";
}
