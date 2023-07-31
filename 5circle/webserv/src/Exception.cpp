#include <iostream>

#include "Exception.hpp"
#include "Http.hpp"

void webserv::occurException(const std::string& file, int line, const std::string& message)
{
	std::cerr << file << ":" << line << " " + message << std::endl;
}

void serverFunctionExecuteFailed(std::string msg)
{
	FT_THROW(msg + "[" + static_cast<const std::string>(strerror(errno)) + "]", SettingHttpException());
}

void serverFunctionExecuteFailed(std::string msg, std::string detail)
{
	FT_THROW(msg + " " + detail, SettingHttpException());
}

const char* EmptyFileException ::what() const throw() { return ("Error : Empty File"); }
const char* NoSuchFileException ::what() const throw() { return ("Error : No Such File"); }
const char* ServerPortOverlapException ::what() const throw() { return ("Error : Server Port Overlap"); }
const char* notValidAddrException ::what() const throw() { return ("Error : Is Not Valid Address"); }
const char* NotValidConfigFileException ::what() const throw() { return ("Error : Not Valid Configuration File"); }
const char* SettingHttpException ::what() const throw() { return ("Error : Fail Server Setting function"); }
const char* LocationRootOverlapException ::what() const throw() { return ("Error : Location Block Default Root Overlap"); }
const char* RunServerException ::what() const throw() { return ("Error : Occured Exception During Run Server"); }
const char* RunCgiException ::what() const throw() { return ("Error : An error occurred during CGI execution."); }
