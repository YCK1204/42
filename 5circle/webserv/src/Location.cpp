#include "Location.hpp"

Location::Location()
{
	_ret = false;
	_autoindex = false;
	for (int i = 0; i < 3; i++)
		_methods[i] = true;

	_cgi = "";
	_root = "";
	_index = "";
	_redirect = "";
	_default_root = "";
}

Location::~Location() { }

Location::Location(const Location& l)
{
	_ret = l._ret;
	_autoindex = l._autoindex;
	setMethodsFlag(l._methods);
	_cgi = l._cgi;
	_root = l._root;
	_index = l._index;
	_redirect = l._redirect;
	_default_root = l._default_root;
}

void Location::setReturnFlag(bool const& flag)
{
	_ret = flag;
}

void Location::setAutoindexFlag(bool const& flag)
{
	_autoindex = flag;
}

void Location::setMethodsFlag(bool const flag[3])
{
	for (int i = 0; i < 3; i++)
		_methods[i] = flag[i];
}

void Location::setCgi(std::string const& cgi)
{
	_cgi = cgi;
}

void Location::setRoot(std::string const& root)
{
	_root = root;
}

void Location::setIndex(std::string const& index)
{
	_index = index;
}

void Location::setRedirect(std::string const& redirect)
{
	_redirect = redirect;
}

void Location::setDefaultRoot(std::string const& default_root)
{
	_default_root = default_root;
}

bool Location::getRet() const
{
	return _ret;
}

bool Location::getAutoindex() const
{
	return _autoindex;
}

bool Location::getMethods(int idx) const
{
	return _methods[idx];
}

std::string const Location::getCgi() const
{
	return _cgi;
}

std::string const Location::getRoot() const
{
	return _root;
}

std::string const Location::getIndex() const
{
	return _index;
}

std::string const Location::getRedirect() const
{
	return _redirect;
}

std::string const Location::getDefaultRoot() const
{
	return _default_root;
}
