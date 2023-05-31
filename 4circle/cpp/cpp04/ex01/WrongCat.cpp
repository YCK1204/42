/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:14 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 12:54:00 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default Constructor called" << std::endl; 
}

WrongCat::WrongCat(std::string type)
{
	this->type = type;
	std::cout << "WrongCat Copy type Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &w)
{
	this->type = w.type;
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &w)
{
	if (this != &w)
	{
		this->type = w.type;
		std::cout << "WrongCat Copy Assignment called" << std::endl;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}


void	WrongCat::makeSound() const
{
	std::cout << "Wrong meow" << std::endl;
}
