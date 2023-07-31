#include "Exception.hpp"
#include "Http.hpp"
#include "Location.hpp"
#include <sstream>

Location& Location::makeLocation(std::ifstream& file, std::stringstream& ss)
{
	std::string line, cmd, tmp, temp, tt;
	int types[6] = {}, t = 0;

	this->_ret = false;
	this->_autoindex = false;
	this->_methods[0] = true;
	this->_methods[1] = true;
	this->_methods[2] = true;
	this->_cgi = "";
	this->_root = "";
	this->_index = "";
	this->_redirect = "";
	this->_default_root = "";

	ss >> tmp >> temp >> tt;
	if (temp.compare("{")) {
		FT_THROW(line + " location is not started \"location default_root {\"", NotValidConfigFileException());
	} else if (!tt.empty()) {
		FT_THROW(line + " location is not started \"location default_root {\"", NotValidConfigFileException());
	}
	setDefaultRoot(tmp);
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		std::stringstream ss(line);
		ss >> cmd;
		if (!cmd.compare("}") && ++t)
			break;
		setLocationOption(ss, cmd, types);
	}
	if (t != 1) {
		FT_THROW(line + " location is not finished \"}\"", NotValidConfigFileException());
	}
	if (getAutoindex()) {
		for (int i = 0; i < 3; i++)
			_methods[i] = true;
	}
	return *this;
}

void Location::setLocationOption(std::stringstream& ss, std::string cmd, int types[6])
{
	if (!cmd.compare("allow_methods") && ++types[METHOD]) {
		buildLocationOption(ss, *this);
	} else if (!cmd.compare("autoindex") && ++types[AUTOINDEX]) {
		setAutoindexFlag(buildLocationOption(ss, ""));
	} else if (!cmd.compare("root") && ++types[L_ROOT]) {
		setRoot(buildLocationOption(ss));
	} else if (!cmd.compare("index") && ++types[L_INDEX]) {
		setIndex(buildLocationOption(ss));
	} else if (!cmd.compare("return") && ++types[RETURN] && (_ret = true)) {
		setRedirect(buildLocationOption(ss));
	} else if (!cmd.compare("cgi-bin") && ++types[CGI]) {
		setCgi(buildLocationOption(ss));
	} else {
		FT_THROW(" location block option error", NotValidConfigFileException());
	}
}

void Location::buildLocationOption(std::stringstream& ss, Location& ret)
{
	std::string t, t1, t2, t3;
	int type[3] = {}, tmp;

	type[0] = false;
	type[1] = false;
	type[2] = false;
	for (;;) {
		t.clear();
		ss >> t;
		if (t.empty())
			break;
		tmp = distinctionMethods(t);
		type[tmp]++;
	}
	for (int i = 0; i < 3; i++) {
		if (type[i] > 1)
			FT_THROW("method should only appear once", NotValidConfigFileException());
	}
	bool return_type[3];

	for (int i = 0; i < 3; i++)
		if (type[i])
			return_type[i] = true;
	ret.setMethodsFlag(return_type);
}

int Location::distinctionMethods(std::string& method)
{
	int ret = 0;

	if (!method.compare("GET"))
		ret = 0;
	else if (!method.compare("POST"))
		ret = 1;
	else if (!method.compare("DELETE"))
		ret = 2;
	else
		FT_THROW(method + " methods must (GET, POST, DELETE)", NotValidConfigFileException());
	return ret;
}

bool Location::buildLocationOption(std::stringstream& ss, std::string tt)
{
	std::string t;
	bool ret = false;

	ss >> t >> tt;
	if (!t.compare("on"))
		ret = true;
	else if (!t.compare("off"))
		ret = false;
	else if (!tt.empty())
		FT_THROW(t + " autoindex must on or off", NotValidConfigFileException());
	return ret;
}

std::string Location::buildLocationOption(std::stringstream& ss)
{
	std::string t, tt;

	ss >> t >> tt;
	if (!tt.empty())
		FT_THROW(tt + " bad argument location option", NotValidConfigFileException());
	return t;
}
