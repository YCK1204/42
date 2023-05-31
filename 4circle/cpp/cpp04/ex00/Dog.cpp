/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:52:05 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 12:53:10 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default Constructor called" << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
	std::cout << "Dog Copy type Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &d)
{
	*this = d;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog	&Dog::operator = (const Dog &d)
{
	if (this != &d)
	{
		this->type = d.type;
		std::cout << "Dog Copy assignment called" << std::endl;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog makeSound " << getType() << " : Bow" << std::endl;
}
