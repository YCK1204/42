#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <iostream>
#include <sstream>
#include <string>

class Location {
private:
	Location& operator=(const Location& l);

	bool _ret;
	bool _autoindex;
	bool _methods[3];

	std::string _cgi;
	std::string _root;
	std::string _index;
	std::string _redirect;
	std::string _default_root;

	void setLocationOption(std::stringstream& ss, std::string cmd, int types[6]);
	void buildLocationOption(std::stringstream& ss, Location& ret);
	bool buildLocationOption(std::stringstream& ss, std::string tt);
	std::string buildLocationOption(std::stringstream& ss);
	int distinctionMethods(std::string& method);

public:
	Location(const Location& l);
	Location();
	~Location();

	Location& makeLocation(std::ifstream& file, std::stringstream& ss);

	void setReturnFlag(bool const& flag);
	void setAutoindexFlag(bool const& flag);
	void setMethodsFlag(bool const flag[3]);
	void setCgi(std::string const& cgi);
	void setRoot(std::string const& root);
	void setIndex(std::string const& index);
	void setRedirect(std::string const& redirect);
	void setDefaultRoot(std::string const& default_root);

	bool getRet() const;
	bool getAutoindex() const;
	bool getMethods(int idx) const;

	std::string const getCgi() const;
	std::string const getRoot() const;
	std::string const getIndex() const;
	std::string const getRedirect() const;
	std::string const getDefaultRoot() const;
};

#endif
