/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:49:41 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 16:25:50 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->b = new Brain();
	std::cout << "Cat default Constructor called" << std::endl;
}

Cat::Cat(std::string type)
{
	this->type = type;
	this->b = new Brain();
	std::cout << "Cat Copy type Constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->b;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->b = NULL;
	*this = c;
}

Cat &Cat::operator = (const Cat &c)
{
	if (this != &c)
	{
		this->type = c.type;
		if (this->b)
			delete [] this->b;
		this->b = new Brain();
		for (int i = 0; i < 100; i++)
			this->b->setIdea(c.b->getIdea(i), i);
		std::cout << "Cat Copy assignment called" << std::endl;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat makeSound " << getType() << " : meow" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->b);
}

std::string	Cat::getBrain(int idx) const
{
	return (this->b->getIdea(idx));
}
