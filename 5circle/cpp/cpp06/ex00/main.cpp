/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:15:51 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 21:44:15 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	print(std::string c, std::string i, std::string f, std::string d)
{
	std::cout << "char: " + c << std::endl;
	std::cout << "int: " + i << std::endl;
	std::cout << "float: " + f << std::endl;
	std::cout << "double: " + d << std::endl;
}

void	print(std::string c, std::string i, std::string f, double d, int p)
{
	if (c.length() == 1)
		std::cout << "char: '" + c + "'"<< std::endl;
	else
		std::cout << "char: " + c << std::endl;
	std::cout << "int: " + i << std::endl;
	std::cout << "float: " + f << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(p) << d << std::endl;
}

void	print(std::string c, std::string i, float f, double d, int p)
{
	if (c.length() == 1)
		std::cout << "char: '" + c + "'"<< std::endl;
	else
		std::cout << "char: " + c << std::endl;
	std::cout << "int: " + i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(p) << f << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(p) << d << std::endl;
}

void	printType(std::string str)
{
	char	c;
	std::string	cc;
	std::string	i;
	std::string	f;
	std::string	d;

	if (ScalarConverter::getErr())
	{
		cc = "impossible";
		i = "impossible";
		f = str + "f";
		d = str;
	}
	else if (str.length() != 1 && ScalarConverter::getIsString())
	{
		cc = "impossible";
		i = "impossible";
		f = "impossible";
		d = "impossible";
	}
	else
	{
		c = ScalarConverter::getChar();
		ScalarConverter::countDecimalPlaces(str);
		if (ScalarConverter::getOverflowChar())
			cc = "overflow";
		else if (c < 32 && (!(9 <= c && c <= 13) || c > 126))
			cc = "Non displayble";
		else
			cc += ScalarConverter::getChar();
		if (ScalarConverter::getOverflowInt())
			i = "overflow";
		else
		{
			std::stringstream ss;
			ss << ScalarConverter::getInt();
			ss >> i;
		}
		if (ScalarConverter::getOverflowFloat())
			f = "overflow";
	}
	if (!d.empty() && f.empty())
		print(cc, i, f, ScalarConverter::getDouble(), ScalarConverter::getDecimalPlaces());
	else if (d.empty() && f.empty())
		print(cc, i, ScalarConverter::getFloat(), ScalarConverter::getDouble(), ScalarConverter::getDecimalPlaces());
	else
		print(cc, i, f, d);
}

int main(int ac, char **av)
{
	std::string av1;

	if (ac == 2)
	{
		av1 = static_cast<std::string>(av[1]);
		ScalarConverter::convert(av1);
		ScalarConverter::checkOverflow(av1);
		printType(av1);
	}
	else
		std::cerr << "Error number of arguments is incorrect." << std::endl;
	return (0);
}
