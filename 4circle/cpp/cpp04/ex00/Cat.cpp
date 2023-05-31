/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:49:41 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 12:53:00 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default Constructor called" << std::endl;
}

Cat::Cat(std::string type)
{
	this->type = type;
	std::cout << "Cat Copy type Constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
	*this = c;
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &c)
{
	if (this != &c)
	{
		this->type = c.type;
		std::cout << "Cat Copy assignment called" << std::endl;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat makeSound " << getType() << " : meow" << std::endl;
}
