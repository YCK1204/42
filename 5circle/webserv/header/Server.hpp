#ifndef SERVER_HPP
#define SERVER_HPP

// #include "Http.hpp"
#include "Location.hpp"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <vector>

class Location;
class Http;

class Server {
private:
	Server& operator=(const Server& s);
	std::vector<Location> location;

	struct sockaddr_in _serv_adr;
	std::string _root;
	std::string _host;
	std::string _index;
	std::string _error_page;
	std::string _index_root;
	std::string _server_name;

	int _port;
	int _serv_sock;
	int _client_body_size;

	std::string buildServerOption(std::stringstream& ss);
	void setServerOption(std::stringstream& ss, std::string cmd, int types[7]);
	void checkValidServerOption(int types[7]);

public:
	Server();
	~Server();
	Server(const Server& s);

	Server& makeServer(std::ifstream& file);

	void setRoot(std::string const& root);
	void setHost(std::string const& host);
	void setIndex(std::string const& index);
	void setErrPage(std::string const& err_page);
	void setIndexRoot(std::string const& index_root);
	void setServerName(std::string const& name);
	void setPort(int const& port);
	void setServerSock(int const& serv_sock);
	void setClientBodySize(int const& body_size);
	void setSockadr(struct sockaddr_in adr);
	std::string getRoot() const;
	std::string getHost() const;
	std::string getIndex() const;
	std::string getErrPage() const;
	std::string getIndexRoot() const;
	std::string getServerName() const;

	std::vector<Location> getLocations() const;

	struct sockaddr_in getSockadr() const;

	int getPort() const;
	int getServerSock() const;
	int getClientsBodySize() const;

	void setServer();
};

#endif
