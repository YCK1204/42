/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:30:14 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 12:52:50 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal default Constructor called" << std::endl; 
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal Copy type Constructor called" << std::endl;
}

Animal &Animal::operator = (const Animal &a)
{
	if (this != &a)
	{
		this->type = a.type;
		std::cout << "Animal Copy assignment called" << std::endl;
	}
	return (*this);
}

Animal::Animal(const Animal &a)
{
	*this = a;
	std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal makeSound " << getType() << " : ???" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
