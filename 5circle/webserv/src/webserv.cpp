#include "Http.hpp"

int main(int ac, char* av[])
{
	if (ac != 1 && ac != 2) {
		std::cerr << "Error : No Argument" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string file_path = ac == 1 ? "./config/default.conf" : static_cast<std::string>(av[1]);
	try {
		Http serv(static_cast<std::string>(file_path));
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
