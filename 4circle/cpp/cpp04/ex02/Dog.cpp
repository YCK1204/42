/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:52:05 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 15:23:27 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->b = new Brain();
	std::cout << "Dog default Constructor called" << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
	this->b = new Brain();
	std::cout << "Dog Copy type Constructor called" << std::endl;
}

Dog::~Dog()
{
	delete	this->b;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &d)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->b = NULL;
	*this = d;
}

Dog	&Dog::operator = (const Dog &d)
{
	if (this != &d)
	{
		if (this->b)
			delete [] this->b;
		this->b = new Brain();
		for (int i = 0; i < 100; i++)
			this->b->setIdea(d.b->getIdea(i), i);
		this->type = d.type;
		std::cout << "Dog Copy assignment called" << std::endl;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog makeSound " << getType() << " : Bow" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->b);
}

std::string	Dog::getBrain(int idx) const
{
	return (this->b->getIdea(idx));
}
