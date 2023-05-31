/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:13:26 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 12:53:17 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default Constructor called" << std::endl; 
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal Copy type Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &w)
{
	this->type = w.type;
	std::cout << "WrongAnimal Copy Constructor called";
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &a)
{
	if (this != &a)
	{
		this->type = a.type;
		std::cout << "WrongAnimal Copy Assignment called" << std::endl;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Fuxx" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
