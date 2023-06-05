/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:59:07 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/20 14:03:29 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstring>

class BitcoinExchange
{
private:
	std::vector<std::pair<float, std::string> > data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &b);
	BitcoinExchange &operator = (const BitcoinExchange &b);
	~BitcoinExchange();
	size_t	getSize() const;
	float		getValue(int idx) const;
	std::string	getDate(int idx) const;
	void	push(float value, std::string date);
	class tooLargeException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class tooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class noFileException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class emptyFileException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class wrongFormatException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};
#endif
