#include "Http.hpp"
#include <iterator>
#include <string>

std::string Http::failedSign(std::string id, std::string passwd, std::string file_path)
{
	std::string line, total;

	total = readFile(file_path);
	total.insert(total.find("id=\"id\"") - 1, "value=\"" + id + "\"");
	total.insert(total.find("id=\"password\"") - 1, "value=\"" + passwd + "\"");
	return total;
}

bool Http::isMember(std::string id, std::string passwd)
{
	std::string total;

	total = readFile("./member/members.csv");
	std::size_t f = total.find("\n" + id + ",");
	if (f == std::string::npos)
		return false;
	f += id.length() + 2;

	return total.find(passwd, f) != std::string::npos;
}

bool Http::isMember(std::string id)
{
	std::string total;

	total = readFile("./member/members.csv");
	return total.find("\n" + id + ",") != std::string::npos;
}

void Http::registerMember(std::string id, std::string passwd, int clnt_sock)
{
	std::fstream file;

	file.open("./member/members.csv", std::ios::out | std::ios::app);
	file << (id + "," + passwd);
	file.close();
	clients[clnt_sock].cookie = "id=" + id + ";path=/\r\n";
}

void Http::deleteMember(std::string id)
{
	std::string line, total, file_path;
	std::fstream file;

	file_path = "./member/members.csv";
	total = readFile(file_path);

	std::size_t len = total.find("\n" + id + ",") + 1;
	std::size_t next_newline = total.find("\n", len);
	total.erase(len, next_newline - (len - 1));
	file.open(file_path.c_str(), std::ios::out | std::ios::trunc);
	file.write(total.c_str(), total.length());
	file.close();
}

std::string Http::SignIn(std::string body, int clnt_sock)
{
	std::string id, passwd;

	if (!clients[clnt_sock].cookie.empty()) {
		clients[clnt_sock].redirect = "/";
		status = 302;
		return "";
	}

	id = getId(body);
	passwd = cgiSha_256(getPassword(body));
	passwd = passwd.substr(0, passwd.length() - 1);

	if (isMember(id, passwd)) {
		status = 302;
		clients[clnt_sock].redirect = "/";
		clients[clnt_sock].set_cookie = true;
		return "";
	}
	return failedSign(id, getPassword(body), "./docs/fusion_web/sign_in.html");
}

std::string Http::SignUp(std::string body, int clnt_sock)
{
	std::string msg, id, passwd;

	id = getId(body);
	passwd = getPassword(body);
	sleep(1);
	if (!clients[clnt_sock].cookie.empty()) {
		return "";
	}
	if (isMember(id))
		return failedSign(id, passwd, "./docs/fusion_web/sign_up.html");
	passwd = cgiSha_256(passwd);
	registerMember(id, passwd, clnt_sock);
	clients[clnt_sock].set_cookie = true;
	clients[clnt_sock].redirect = "/";
	status = 302;
	return "";
}

std::string Http::SignOut(std::string body, int clnt_sock)
{
	std::string session_id;
	std::size_t len = body.find("=");
	SessionData data;

	session_id = body.substr(len + 1);

	checkCookie(clnt_sock);
	if (!clients[clnt_sock].delete_cookie) {
		data = getMemberData(session_id);
		deleteMember(data.id);
		clients[clnt_sock].delete_cookie = true;
		deleteSession(session_id);
	}
	return "";
}
