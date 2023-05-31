/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:33:05 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/30 16:59:43 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
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
}

ClapTrap &ClapTrap::operator = (const ClapTrap &c)
{
	if (this != &c)
	{
		this->name = c.name;
		this->hitPoint = c.hitPoint;
		this->energyPoint = c.energyPoint;
		this->attackDamage = c.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoint <= 0)
		std::cout << this->name + " died" << std::endl;
	else if (this->energyPoint <= 0)
		std::cout << this->name + " energy point : "<< this->hitPoint << " can not attack" << std::endl;
	else
	{
		std::cout << this->name + " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoint -= static_cast<int>(amount);
	std::cout <<  this->name + " was attacked" << ", hitPoint : " << this->hitPoint << std::endl;
	if (this->hitPoint <= 0)
		std::cout << this->name + " died" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint <= 0)
		std::cout << this->name + " died" << std::endl;
	else if (this->energyPoint <= 0)
		std::cout << this->energyPoint << " energy point : " << this->energyPoint << ", cannot repair" << std::endl; 
	else
	{
		std::cout << this->name + " succesfully repaired!, hit point : " << this->hitPoint;
		this->hitPoint += static_cast<int>(amount);
		std::cout << " -> " << this->hitPoint << std::endl;
		this->energyPoint--;
	}
}
