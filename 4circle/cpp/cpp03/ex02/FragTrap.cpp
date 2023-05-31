/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:10:40 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/02 03:11:52 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &c)
{
	*this= c;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " + this->name + " created" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &c)
{
	if (this != &c)
	{
		this->name = c.name;
		this->hitPoint = c.hitPoint;
		this->energyPoint = c.energyPoint;
		this->attackDamage = c.attackDamage;
		std::cout << "FragTrap " + this->name + " created" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " + this->name + " destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->hitPoint <= 0)
	{
		std::cout << "FragTrap " + this->name + " died" << std::endl;
	}                 
	else if (this->energyPoint <= 0)
	{                 
		std::cout << "FragTrap " + this->name + " energy point : "<< this->hitPoint << " can not attack" << std::endl;
	}                 
	else              
	{                 
		std::cout << "FragTrap " + this->name + " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	this->hitPoint -= static_cast<int>(amount);
	std::cout <<  "FragTrap " + this->name + " was attacked" << ", hitPoint : " << this->hitPoint << std::endl;
	if (this->hitPoint <= 0)
		std::cout << "FragTrap " + this->name + " died" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint <= 0)
		std::cout << "FragTrap " + this->name + " died" << std::endl;
	else if (this->energyPoint <= 0)
		std::cout << "FragTrap " << this->energyPoint << " energy point : " << this->energyPoint << ", cannot repair" << std::endl; 
	else
	{
		std::cout << "FragTrap " + this->name + " succesfully repaired!, hit point : " << this->hitPoint;
		this->hitPoint += static_cast<int>(amount);
		std::cout << " -> " << this->hitPoint << std::endl;
		this->energyPoint--;
	}
}

void	FragTrap::highFivesGuys(void)
{
	if (this->hitPoint <= 0)
		std::cout << this->name +" hit point : "<< this->hitPoint << " can not highfive (FragTrap)" << std::endl;
	else if (this->energyPoint <= 0)
		std::cout << this->name + " energy point : "<< this->hitPoint << " can not highfive (FragTrap)" << std::endl;
	else
	{
		std::cout << this->name + " has highfive (FragTrap)" << std::endl;
		this->energyPoint--;
	}
}
