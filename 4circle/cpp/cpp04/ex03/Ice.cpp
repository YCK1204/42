/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:39:37 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/24 15:03:18 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice &i)
{
	this->type = i.type;
}

Ice &Ice::operator = (const Ice &i)
{
	if (this != &i)
		this->type = i.type;
	return (*this);
}

Ice::~Ice() {} 

Ice::Ice(std::string const &type)
{
	this->type = type;
}

std::string const &Ice::getType() const
{
	return (this->type);
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " + target.getName() + " *$" << std::endl;
}
