/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:26:27 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/26 00:34:00 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	contact::ADD(int *i)
{
	std::string	temp;

	std::cout << "First Name : ";
	cinStr(&temp);
	this->firstName = temp;
	std::cout << "Last Name : ";
	cinStr(&temp);
	this->lastName = temp;
	std::cout << "Nick Name : ";
	cinStr(&temp);
	this->nickName = temp;
	std::cout << "Phone Number : ";
	cinStr(&temp);
	this->phoneNum = temp;
	std::cout << "Darkest Secret : ";
	cinStr(&temp);
	this->secret = temp;
}

void	contact::SEARCH(int *i)
{
	std::string tmp;
	std::cout << std::setw(9);
	std::cout << *i << "|";
	std::cout << std::setw(10);
	tmp = this->firstName;
	if (this->firstName.length() >= 11)
	{
		tmp[9] = '.';
		tmp.replace(10, tmp.length(), "\0");
	}
	std::cout << tmp << "|";
	std::cout << std::setw(10);
	tmp = this->lastName;
	if (this->lastName.length() >= 11)
	{
		tmp[9] = '.';
		tmp.replace(10, tmp.length(), "\0");
	}
	std::cout << tmp << "|";
	std::cout << std::setw(10);
	tmp = this->nickName;
	if (this->nickName.length() >= 11)
	{
		tmp[9] = '.';
		tmp.replace(10, tmp.length(), "\0");
	}
	std::cout << tmp << std::endl;
}

void	contact::printInfo(int idx)
{
	std::cout << "Index : " << idx << std::endl;
	std::cout << "FirstName : " + this->firstName << std::endl;
	std::cout << "LastName : " + this->lastName << std::endl;
	std::cout << "LasttName : " + this->nickName << std::endl;
}
