#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN		data;
	double	ret;
	double	val1;
	double	val2;
	char	*token;
	char	tmp[100];
	char	*temp;

	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	else
	{
		token = std::strtok(av[1], " ");
		for (; token;)
		{
			if (std::strlen(token) > 1)
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			else if ('0' <= token[0] && token[0] <= '9')
				data.push(static_cast<double>(token[0] - '0'));
			else if (data.getSize() > 1)
			{
				val2 = data.pop();
				val1 = data.pop();
				if (token[0] == '-')
					data.push(val1 - val2);
				else if (token[0] == '+')
					data.push(val1 + val2);
				else if (token[0] == '*')
					data.push(val1 * val2);
				else if (token[0] == '/')
					data.push(val1 / val2);
				else
				{
					std::cout << "Error" << std::endl;
					return (1);
				}
			}
			else
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			token = std::strtok(NULL, " ");
		}
		ret = data.pop();
		if (data.getSize())
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
		std::stringstream ss;
		ss << ret;
		ss >> tmp;
		temp = std::strchr(tmp, '.');
		if (temp == NULL)
			std::cout << ret << std::endl;
		else
		{
			int	len = 1;
			for (; temp[len]; len++)
				;
			std::cout << std::fixed << std::setprecision(len - 1) << ret << std::endl;
		}
	}
	return (0);
}
