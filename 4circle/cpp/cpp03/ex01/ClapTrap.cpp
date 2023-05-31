/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:33:05 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/30 17:05:59 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	*this = c;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " + this->name + " created" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &c)
{
	if (this != &c)
	{
		this->name = c.name;
		this->hitPoint = c.hitPoint;
		this->energyPoint = c.energyPoint;
		this->attackDamage = c.attackDamage;
		std::cout << "ClapTrap " + this->name + " created" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " + this->name + " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hitPoint <= 0)
	{
		std::cout << "ClapTrap " + this->name + " died" << std::endl;
	}                 
	else if (this->energyPoint <= 0)
	{                 
		std::cout << "ClapTrap " + this->name + " energy point : "<< this->hitPoint << " can not attack" << std::endl;
	}                 
	else              
	{                 
		std::cout << "ClapTrap " + this->name + " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoint -= static_cast<int>(amount);
	std::cout <<  "ClapTrap " + this->name + " was attacked" << ", hitPoint : " << this->hitPoint << std::endl;
	if (this->hitPoint <= 0)
		std::cout << "ClapTrap " + this->name + " died" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint <= 0)
		std::cout << "ClapTrap " + this->name + " died" << std::endl;
	else if (this->energyPoint <= 0)
		std::cout << "ClapTrap " << this->energyPoint << " energy point : " << this->energyPoint << ", cannot repair" << std::endl; 
	else
	{
		std::cout << "ClapTrap " + this->name + " succesfully repaired!, hit point : " << this->hitPoint;
		this->hitPoint += static_cast<int>(amount);
		std::cout << " -> " << this->hitPoint << std::endl;
		this->energyPoint--;
	}
}
