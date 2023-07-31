#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

#define FT_THROW(message, exception)                          \
	do {                                                      \
		webserv::occurException(__FILE__, __LINE__, message); \
		throw exception;                                      \
	} while (0)

namespace webserv {
void occurException(const std::string& file, int line, const std::string& message);
}

#endif
