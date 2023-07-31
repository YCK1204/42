#include "Server.hpp"
#include "Http.hpp"
#include "Location.hpp"

Server::Server()
{
	_port = 0;
	_serv_sock = 0;
	_client_body_size = 0;

	location.clear();
	_root = "";
	_host = "";
	_index = "";
	_error_page = "";
	_index_root = "";
	_server_name = "";
	std::memset(&_serv_adr, 0, sizeof(_serv_adr));
}

Server::Server(const Server& s)
{

	_port = s._port;
	_serv_sock = s._serv_sock;
	_client_body_size = s._client_body_size;

	location.clear();
	for (std::size_t i = 0; i < s.location.size(); i++) {
		location.push_back(s.location[i]);
	}

	_root = s._root;
	_host = s._host;
	_index = s._index;
	_error_page = s._error_page;
	_index_root = s._index_root;
	_server_name = s._server_name;
	std::memset(&_serv_adr, 0, sizeof(_serv_adr));
}

Server::~Server() { }

void Server::setRoot(std::string const& root)
{
	_root = root;
}

void Server::setHost(std::string const& host)
{
	_host = host;
}

void Server::setIndex(std::string const& index)
{
	_index = index;
}

void Server::setErrPage(std::string const& err_page)
{
	_error_page = err_page;
}

void Server::setIndexRoot(std::string const& index_root)
{
	_index_root = index_root;
}

void Server::setServerName(std::string const& name)
{
	_server_name = name;
}

void Server::setPort(int const& port)
{
	_port = port;
}

void Server::setServerSock(int const& serv_sock)
{
	_serv_sock = serv_sock;
}

void Server::setClientBodySize(int const& body_size)
{
	_client_body_size = body_size;
}

void Server::setSockadr(struct sockaddr_in adr)
{
	_serv_adr = adr;
}

std::string Server::getRoot() const
{
	return _root;
}

std::string Server::getHost() const
{
	return _host;
}

std::string Server::getIndex() const
{
	return _index;
}

std::string Server::getErrPage() const
{
	return _error_page;
}

std::string Server::getIndexRoot() const
{
	return _index_root;
}

std::string Server::getServerName() const
{
	return _server_name;
}

int Server::getPort() const
{
	return _port;
}

int Server::getServerSock() const
{
	return _serv_sock;
}

int Server::getClientsBodySize() const
{
	return _client_body_size;
}

std::vector<Location> Server::getLocations() const
{
	return location;
}

struct sockaddr_in Server::getSockadr() const
{
	return _serv_adr;
}

void Server::setServer()
{
	int t = 1;
	if ((setsockopt(_serv_sock, SOL_SOCKET, SO_REUSEADDR, &t, sizeof(t))) == -1)
		serverFunctionExecuteFailed("setsockopt()");
	if ((bind(_serv_sock, (struct sockaddr*)&_serv_adr, sizeof(_serv_adr))) == -1)
		serverFunctionExecuteFailed("bind()");
}
