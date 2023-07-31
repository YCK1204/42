#include "ft.hpp"
#include <cstring>

char* ft::strdup(const char* source)
{
	char* const result = new char[std::strlen(source) + 1];
	strcpy(result, source);
	return result;
}
