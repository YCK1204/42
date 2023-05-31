/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SvTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   eated: 2023/01/30 17:24:47 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/30 17:02:57 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &c)
{
	*this= c;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " + this->name + " created" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &c)
{
	if (this != &c)
	{
		this->name = c.name;
		this->hitPoint = c.hitPoint;
		this->energyPoint = c.energyPoint;
		this->attackDamage = c.attackDamage;
		std::cout << "ScavTrap " + this->name + " created" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " + this->name + " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hitPoint <= 0)
	{
		std::cout << "ScavTrap " + this->name + " died" << std::endl;
	}                 
	else if (this->energyPoint <= 0)
	{                 
		std::cout << "ScavTrap " + this->name + " energy point : "<< this->hitPoint << " can not attack" << std::endl;
	}                 
	else              
	{                 
		std::cout << "ScavTrap " + this->name + " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	this->hitPoint -= static_cast<int>(amount);
	std::cout <<  "ScavTrap " + this->name + " was attacked" << ", hitPoint : " << this->hitPoint << std::endl;
	if (this->hitPoint <= 0)
		std::cout << "ScavTrap " + this->name + " died" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint <= 0)
		std::cout << "ScavTrap " + this->name + " died" << std::endl;
	else if (this->energyPoint <= 0)
		std::cout << "ScavTrap " << this->energyPoint << " energy point : " << this->energyPoint << ", cannot repair" << std::endl; 
	else
	{
		std::cout << "ScavTrap " + this->name + " succesfully repaired!, hit point : " << this->hitPoint;
		this->hitPoint += static_cast<int>(amount);
		std::cout << " -> " << this->hitPoint << std::endl;
		this->energyPoint--;
	}
}

void	ScavTrap::guardGate()
{
	if (this->hitPoint <= 0)
		std::cout << this->name + " hit point : "<< this->hitPoint << " can not guard (ScavTrap)" << std::endl;
	else if (this->energyPoint <= 0)
		std::cout << this->name + " energy point : "<< this->hitPoint << " can not guard (ScavTrap)" << std::endl;
	else
	{
		std::cout << this->name + " has entered guard mode (ScavTrap)" << std::endl;
		this->energyPoint--;
	}
}
