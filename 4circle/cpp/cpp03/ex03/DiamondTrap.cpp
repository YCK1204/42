/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:41:01 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/02 03:25:31 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &c)
{
	ClapTrap::name = c.name + "_clap_name";
	*this = c;
	std::cout << "DiamondTrap " + this->name + " Copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " + this->name + " created" << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &c)
{
	if (this != &c)
	{
		this->name = c.name;
		this->hitPoint = c.hitPoint;
		this->energyPoint = c.energyPoint;
		this->attackDamage = c.attackDamage;
		std::cout << "DiamondTrap " + this->name + " created" << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " + this->name + " destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	this->hitPoint -= static_cast<int>(amount);
	std::cout <<  "DiamondTrap " + this->name + " was attacked" << ", hitPoint : " << this->hitPoint << std::endl;
	if (this->hitPoint <= 0)
		std::cout << "DiamondTrap " + this->name + " died" << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint <= 0)
		std::cout << "DiamondTrap " + this->name + " died" << std::endl;
	else if (this->energyPoint <= 0)
		std::cout << "DiamondTrap " << this->energyPoint << " energy point : " << this->energyPoint << ", cannot repair" << std::endl; 
	else
	{
		std::cout << "DiamondTrap " + this->name + " succesfully repaired!, hit point : " << this->hitPoint;
		this->hitPoint += static_cast<int>(amount);
		std::cout << " -> " << this->hitPoint << std::endl;
		this->energyPoint--;
	}
}

void	DiamondTrap::whoAmI()
{
	std::cout << "this DiamondTrap name is " + this->name + " and this ClapTrap name is " + ClapTrap::name << std::endl;
}
