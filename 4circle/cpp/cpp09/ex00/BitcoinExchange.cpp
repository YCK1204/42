/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:09:21 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/20 14:03:59 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &b){*this = b;}
BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &b)
{
	if (this != &b)
	{
		this->data.clear();
		for (size_t i = 0; i < b.data.size(); i++)
			this->data.push_back(std::make_pair(b.data[i].first, b.data[i].second));
	}
	return (*this);
}
size_t	BitcoinExchange::getSize() const{return (this->data.size());}
float	BitcoinExchange::getValue(int idx) const{return (this->data[idx].first);}
std::string	BitcoinExchange::getDate(int idx) const{return (this->data[idx].second);}
BitcoinExchange::~BitcoinExchange() {}
void	BitcoinExchange::push(float value, std::string date){this->data.push_back(make_pair(value, date));}
const char *BitcoinExchange::tooLargeException::what() const throw() { return ("Error: too large a number."); }
const char *BitcoinExchange::tooLowException::what() const throw() { return ("Error: not a positive number."); }
const char *BitcoinExchange::noFileException::what() const throw() { return ("Error: could not open file."); }
const char *BitcoinExchange::emptyFileException::what() const throw() { return ("Error: NULL file."); }

const char *BitcoinExchange::wrongFormatException::what() const throw() { return ("Error: Wrong Format."); }


