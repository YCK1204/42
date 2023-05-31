/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:26:38 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/21 19:41:36 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	isValidDate(std::string date)
{
	int	year;
	int	month;
	int	day;
	int	leapYear = 0;

	size_t	len = date.length();
	if (len != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < len; i++)
		if ((i != 4 && i != 7) && (date[i] < '0' || '9' < date[i]))
			return (false);
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 7).c_str());
	day = std::atoi(date.substr(8).c_str());
	if (!(year % 4))
	{
		if (!(year % 100))
		{
			if (!(year % 400))
				leapYear = 1;
		}
		else
			leapYear = 1;
	}
	if (!month || !day || month > 12 || day > 31)
		return (false);
	else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		return (false);
	else if (month == 2 && day > 28 + leapYear)
		return (false);
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	return (true);
}

bool	isValidValue(std::string val)
{
	size_t		i = 0;
	size_t		len = val.length();
	int			f = 0;
	int			tmp = 0;
	float		value;

	if (val[i] == '+' || val[i] == '-')
		i++;
	for (; i < len && f < 2 && tmp < 2; i++)
	{
		if ((i == val.length() - 1 && val[i] == 'f' && ++tmp) || (val[i] == '.' && ++f))
			continue ;
		if ('0' > val[i] || '9' < val[i])
			return (false);
	}
	if (f >= 2 || tmp >= 2)
		return (false);
	value = static_cast<float>(std::atof(val.c_str()));
	if (value < 0 || value > 1000)
		return (false);
	return (true);
}

int	main(int ac, char *av[])
{
	std::ifstream	infile;
	std::string		line;
	std::string		date;
	std::string		value;
	std::string		limit;
	std::string		delim;
	std::string		tmp;
	BitcoinExchange	b;
	float			val;
	float			v;
	int				i = 0;

	try
	{
		if (ac == 1)
			throw BitcoinExchange::noFileException();
		else
		{
			infile.open("data.csv");
			if (infile.is_open())
			{
				getline(infile, line);
				if (line.compare("date,exchange_rate"))
				{
					std::cout << "FUCK have been hacked" << std::endl;
					return (1);
				}
				while (getline(infile, line))
				{
					std::stringstream ss(line);
					getline(ss, date, ',');
					getline(ss, value);
					val = std::atof(value.c_str());
					b.push(val, date);
				}
			}
			else
			{
				std::cout << "Error: data.csv not found." << std::endl;
				return (1);
			}
			infile.close();
			while (++i < ac)
			{
				infile.open(av[i]);
				try
				{
					if (!infile.is_open())
						throw BitcoinExchange::noFileException();
					else
					{
						getline(infile, line);
						if (line.empty())
							throw BitcoinExchange::emptyFileException();
						else if (line.compare("date | value"))
							throw BitcoinExchange::wrongFormatException();
						else
						{
							while (getline(infile, line))
							{
								try
								{
									if (line.length() == 0)
										continue ;
									date.clear();
									delim.clear();
									value.clear();
									tmp.clear();
									std::stringstream ss(line);
									ss >> date >> delim >> value >> tmp;
									if (!isValidDate(date) || delim.compare("|") || value.length() == 0 || tmp.length())
										std::cout << "Error: bad input => " + line << std::endl;
									else if (!isValidValue(value))
									{
										val = std::atof(value.c_str());
										if ((0 <= val && val <= 1000) || value.length() == 0)
											std::cout << "Error: bad input => " + line << std::endl;
										else if (val > 1000)
											throw BitcoinExchange::tooLargeException();
										else if (val < 0)
											throw BitcoinExchange::tooLowException();
									}
									else
									{
										int	idx = 0;
										val = std::atof(value.c_str());
										for (; std::strcmp(b.getDate(idx).c_str(), date.c_str()) < 0 && idx < b.getSize(); idx++);
										if (idx < b.getSize() && std::strcmp(b.getDate(idx).c_str(), date.c_str()) > 0)
											idx--;
										v = b.getValue(idx);
										std::cout << date + " => " << val << " = " << val * v << std::endl;
									}
								}
								catch (std::exception &e)
								{
									std::cout << e.what() << std::endl;
								}
							}
						}
					}
				}
				catch (std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
				infile.close();
				if (i + 1 != ac)
					std::cout << ":: =============================== ::" << std::endl;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
