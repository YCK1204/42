#ifndef HTTP_HPP
#define HTTP_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <locale>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include <arpa/inet.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "Location.hpp"
#include "Mime.hpp"
#include "Server.hpp"

class Location;
class Server;

extern pid_t pid;

#define LISTEN_SIZE 20
#define REQUEST_CNT 20
#define BUF_SIZE 2048
#define TIMEOUT 2
#define MAX_ROOT_LEN 30

#define RED "\033[31m"
#define ORANGE "\033[33m"
#define YELLOW "\033[93m"
#define LIME "\033[92m"
#define SKY_BLUE "\033[96m"
#define CLEAR "\033[0m"

#define PYTHON_PATH "/usr/local/bin/python3"
#define PHP_PATH "/usr/bin/php"

enum files {
	F_HTTP,
	PARSING,
	S_PARSING,
	L_PARSING,
	UTIL,
	CLIENT
};

enum exception {
	CONFIG,
	FILEROOT,
	EMPTY,
	PORT,
	ROOT,
	ADDR,
	HTTP,
	SERVER
};

enum s_block_type {
	LISTEN,
	ERROR_PAGE,
	HOST,
	BODY_SIZE,
	S_INDEX,
	S_ROOT,
	SERVER_NAME
};

enum methods {
	GET,
	POST,
	DELETE
};

enum l_block_type {
	METHOD,
	AUTOINDEX,
	L_ROOT,
	L_INDEX,
	RETURN,
	CGI
};

enum cgis {
	KEY,
	SHA,
	CAL,
	SESSION
};

typedef struct {
	std::string display;
	std::string result;
} Calculator;

typedef struct {
	char* buf;
	char* binary_request;

	std::size_t image_size;
} Image;

typedef struct {
	int port;
	int addr[4];
	int request_cnt;

	bool at;
	bool set_cookie;
	bool delete_cookie;

	std::string root;
	std::string http;
	std::string cookie;
	std::string method;
	std::string request;
	std::string redirect;
	std::string http_ver;
	std::string connection;
	std::string body_method;
	std::string body_request;
	std::string file_extension;

	std::size_t str_len;
	std::size_t body_size;
	std::time_t last_active_times;

	Image img;
	Calculator cal;
} ClientData;

struct FileInfo {
	std::string name;
	off_t size;
	time_t lastModified;
	bool is_dir;
};

typedef struct {
	int port;
	std::string id;
	unsigned long start_time;
} SessionData;

class Http {
private:
	fd_set events, read_event, err_event;
	std::vector<Server> server;
	std::map<int, ClientData> clients;
	std::map<std::string, SessionData> session;
	int err, fd_max, status;
	Mime mime;

	Http();
	Http& operator=(const Http& s);

	/* parsing_functions*/
	void checkValidConfig();
	void checkValidServerOption(int types[7]);
	void ParsingConfig(const std::string& path);
	void checkEmptyFile(const std::string& path);
	void checkValidAddr(const std::string& host);
	/* parsing_functions*/

	/* util_functions */
	std::string getDate();
	std::string formatSize(double size);
	std::string getId(std::string body);
	std::string spaceTrim(std::string str);
	std::string getPassword(std::string body);
	std::string formatTime(const time_t& time);
	std::string readFile(std::string file_path);
	std::string decoding(const std::string& encodedString);
	std::string getIndexRoot(Server server, Location location);
	std::string buildAutoindex(std::string server_root, std::string location_root);

	void printConfigInfo();
	void addFdSet(int clnt_sock, fd_set& event);
	void clearFdSet(int clnt_sock, fd_set& event);

	bool isDir(std::string dir_root);
	bool isFile(std::string file_root);
	bool checkValidateAddress(int addr[4]);
	bool checkAccessControl(int clnt_sock);

	Server getServer(int port, std::string root);
	char* ft_strrstr(int clnt_sock, char* str, int size);
	Location getLocation(std::string root, Server server);
	/* util_functions */

	/* server_functions */
	void runServer();
	void SettingHttp();
	void initializeServer();
	/* server_functions */

	/* client_functions*/
	void clientHandler();
	void printLog(int clnt_sock);
	void clientInit(int clnt_sock);
	void eventErrHandler(int clnt_sock);
	void disconnectClient(int clnt_sock);
	/* client_functions*/

	/* read_event_functions */
	void clientAccept(int serv_sock);
	void readRequestMsg(int clnt_sock);
	void eventReadHandler(int clnt_sock);
	/* read_event_functions */

	/* write_event_functions */
	void writeResponse(int clnt_sock);
	void decideConnecting(int clnt_sock);
	/* write_event_functions */

	/* html_functions*/
	std::string buildErrorMsg(int clnt_sock);
	std::string buildHtml(const std::string msg);
	std::string buildErrorHtml(const int status, Server server);
	/* html_functions*/

	/* response_functions */
	std::string getMsg(int clnt_sock, int length);
	std::pair<std::string, std::string> getResponse(int clnt_sock);
	std::pair<std::string, std::string> getPostReseponse(int clnt_sock);
	std::pair<std::string, std::string> buildErrReseponse(int clnt_sock);

	std::string getContent(int clnt_sock);
	std::string receiveFile(int clnt_sock);

	std::string getAutoindex(int clnt_sock, Server& server);
	std::string buildGetResponse(int clnt_sock);

	void setRedirect(int clnt_sock);
	void parsingFormData(int clnt_sock);

	bool decideSignRedirect(int clnt_sock);

	int isAutoindex(int clnt_sock);

	/* response_functions */

	/* sign_finction*/
	std::string cgiSha_256(std::string str);
	std::string SignIn(std::string body, int clnt_sock);
	std::string SignUp(std::string body, int clnt_sock);
	std::string SignOut(std::string body, int clnt_sock);
	std::string failedSign(std::string id, std::string passwd, std::string file_path);

	void deleteMember(std::string id);
	void registerMember(std::string id, std::string passwd, int clnt_sock);

	bool isMember(std::string id);
	bool isRegisteredMember(int clnt_sock);
	bool isMember(std::string id, std::string passwd);

	/* sign_finction*/

	/* session functions */
	SessionData makeSession(int clnt_sock);
	SessionData getMemberData(std::string session_id);

	void checkSession(int clnt_sock);
	void deleteSession(std::string session_id);
	/* session functions */

	/* request parsing */
	std::string getCookie(int clnt_sock);
	std::string getRoot(std::string req_msg);
	std::string getHTTP(std::string req_msg);
	std::string getPort(std::string req_msg);
	std::string getMethod(std::string req_msg);
	std::string getAddress(std::string req_msg);
	std::string getHttpVer(std::string req_msg);
	std::string getConnection(std::string req_msg);

	void getData(int clnt_sock);
	void checkRequestMsg(int clnt_sock);

	bool isValidAddress(Server server, int addr[4]);
	/* request parsing */

	/* request body parsing */
	std::string getFileName(int clnt_sock);
	std::string getBodyMethod(int clnt_sock);

	void postHandler(int clnt_sock, std::size_t len);
	void parsingImageData(int clnt_sock);
	void parsingCalculator(int clnt_sock);

	/* request body parsing */

	/* cgi functions*/
	void ft_execve(int fd[2], char** argv, std::string cmd);
	void execveChild(cgis type, std::string file_path, std::string argv, int fd[2]);

	char** getArgv(cgis type, std::string file_path, std::string argv, std::string cmd);

	std::string waitChild(int fd[2]);
	std::string cgiCalculator(int clnt_sock);
	std::string occurDivisionZero(std::string display);
	std::string runCgi(cgis type, std::string file_path, std::string argv, std::string cmd);
	/* cgi functions*/

	/* cookie functions*/
	std::string deleteCookie();
	std::string createCookie(int clnt_sock);

	void checkCookie(int clnt_sock);
	void redirectClient(int clnt_sock, bool set_cookie);
	/* cookie functions*/

public:
	Http(const std::string& path);
	~Http();
};

class NotValidConfigFileException : public std::exception {
public:
	const char* what() const throw();
};
class NoSuchFileException : public std::exception {
public:
	const char* what() const throw();
};
class EmptyFileException : public std::exception {
public:
	const char* what() const throw();
};
class ServerPortOverlapException : public std::exception {
public:
	const char* what() const throw();
};
class LocationRootOverlapException : public std::exception {
public:
	const char* what() const throw();
};
class notValidAddrException : public std::exception {
public:
	const char* what() const throw();
};
class SettingHttpException : public std::exception {
public:
	const char* what() const throw();
};
class RunServerException : public std::exception {
public:
	const char* what() const throw();
};
class RunCgiException : public std::exception {
public:
	const char* what() const throw();
};
int ft_stoi(const std::string& str);

void serverFunctionExecuteFailed(std::string msg);
void serverFunctionExecuteFailed(std::string msg, std::string detail);

#endif
