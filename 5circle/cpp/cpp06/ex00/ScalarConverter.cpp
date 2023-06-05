/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:40:05 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 21:45:12 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::c = 0;
double ScalarConverter::d = 0;
float ScalarConverter::f = 0;
int ScalarConverter::i = 0;
bool ScalarConverter::err = false;
bool ScalarConverter::overflowInt = false;
bool ScalarConverter::overflowFloat = false;
bool ScalarConverter::overflowChar = false;
int	ScalarConverter::decimalPlaces = 1;
bool ScalarConverter::isString = false;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &s)
{
	ScalarConverter::c = s.c;
	ScalarConverter::i = s.i;
	ScalarConverter::f = s.f;
	ScalarConverter::d = s.d;
	ScalarConverter::err = s.err;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &s)
{
	if (this != &s)
	{
		ScalarConverter::c = s.c;
		ScalarConverter::i = s.i;
		ScalarConverter::f = s.f;
		ScalarConverter::d = s.d;
		ScalarConverter::err = s.err;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string str)
{
	if (!str.length() || !str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf") || !str.compare("-inf") || !str.compare("+inf") || !str.compare("nan") || !str.compare("inf") || !str.compare("inff"))
		ScalarConverter::err = true;
	else if (str.length() > 1 && ScalarConverter::IsString(str))
		ScalarConverter::isString = true;
	else if (str.length() == 1)
	{
		if ('0' <= str[0] && str[0] <= '9')
		{
			ScalarConverter::i = std::atoi(str.c_str());
			ScalarConverter::c = static_cast<char>(ScalarConverter::i);
			ScalarConverter::f = static_cast<float>(std::atof(str.c_str()));
			ScalarConverter::d = std::atof(str.c_str());
		}
		else
		{
			ScalarConverter::i = static_cast<int>(str[0]);
			ScalarConverter::c = static_cast<char>(ScalarConverter::i);
			ScalarConverter::f = static_cast<float>(str[0]);
			ScalarConverter::d = static_cast<double>(str[0]);
		}
	}
	else
	{
		ScalarConverter::i = std::atoi(str.c_str());
		ScalarConverter::c = static_cast<char>(ScalarConverter::i);
		ScalarConverter::f = static_cast<float>(std::atof(str.c_str()));
		ScalarConverter::d = std::atof(str.c_str());
	}
}

bool ScalarConverter::IsString(std::string str)
{
	int	i = 0;
	int	c = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; str[i] && c < 2; i++)
	{
		if (str[i] == '.')
			c++;
		else if (str[i] == 'f' && str[i + 1] == '\0')
			continue ;
		else if (!std::isdigit(str[i]))
			return (true);
	}
	if (str[i] || c >= 2)
		return (true);
	return (false);
}

void	ScalarConverter::checkOverflow(const std::string str)
{
	double			d;
	long long		l;

	std::istringstream iss(str);
	std::istringstream is(str);
	iss >> d;
	is >> l;
	if (l > 2147483647 || l < -2147483648)
		ScalarConverter::overflowInt = true;
	if (l > 127 || l < -127)
		ScalarConverter::overflowChar = true;
	if (d > FLT_MAX || d < -FLT_MAX)
		ScalarConverter::overflowFloat = true;
}

void	ScalarConverter::countDecimalPlaces(std::string str)
{
	std::size_t idx = str.find(".", 0);
	if (idx != std::string::npos)
	{
		std::size_t tmp = idx;
		for (; str[idx] && str[idx] != 'f'; idx++);
		ScalarConverter::decimalPlaces = idx - tmp - 1;
		if (!str[tmp + 1])
			ScalarConverter::decimalPlaces = 1;
	}
}

char ScalarConverter::getChar()
{
	return (ScalarConverter::c);
}

int ScalarConverter::getInt()
{
	return (ScalarConverter::i);
}

float ScalarConverter::getFloat()
{
	return (ScalarConverter::f);
}

double ScalarConverter::getDouble()
{
	return (ScalarConverter::d);
}

bool ScalarConverter::getErr()
{
	return (ScalarConverter::err);
}

int ScalarConverter::getDecimalPlaces()
{
	return (ScalarConverter::decimalPlaces);
}

bool ScalarConverter::getIsString()
{
	return (ScalarConverter::isString);
}

bool ScalarConverter::getOverflowChar()
{
	return (ScalarConverter::overflowChar);
}

bool ScalarConverter::getOverflowInt()
{
	return (ScalarConverter::overflowInt);
}

bool ScalarConverter::getOverflowFloat()
{
	return (ScalarConverter::overflowFloat);
}
