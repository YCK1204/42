/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:40:14 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/15 18:23:25 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <locale>
#include <sstream>
#include <cfloat>

class ScalarConverter
{
private:
	static char		c;
	static int		i;
	static float	f;
	static double	d;
	static bool		err;
	static int		decimalPlaces;
	static bool		isString;
	static bool		overflowInt;
	static bool		overflowFloat;
	static bool		overflowChar;
	ScalarConverter();
	ScalarConverter(const ScalarConverter &s);
	ScalarConverter &operator = (const ScalarConverter &s);
	~ScalarConverter();
public:
	static bool IsString(std::string str);
	static void	countDecimalPlaces(std::string str);
	static int getDecimalPlaces();
	static void	convert(std::string str);
	static char getChar();
	static int getInt();
	static float getFloat();
	static double getDouble();
	static bool getErr();
	static bool getIsString();
	static bool getOverflowChar();
	static bool getOverflowInt();
	static bool getOverflowFloat();
	static void checkOverflow(const std::string str);
};

#endif
