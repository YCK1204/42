/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:42:41 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/19 13:24:34 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure &c)
{
	this->type = c.type;
}

Cure &Cure::operator = (const Cure &c)
{
	if (this != &c)
		this->type = c.type;
	return (*this);
}

Cure::~Cure() {}

Cure::Cure(std::string const &type)
{
	this->type = type;
}

std::string const &Cure::getType() const
{
	return (this->type);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() + "'s wounds *$" << std::endl;
}
