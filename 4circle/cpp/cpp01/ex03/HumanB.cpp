/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:06:43 by yeckim            #+#    #+#             */
/*   Updated: 2023/01/31 20:05:54 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << "HumanB " << this->name << " was created but he is unarmed" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->name << " is dead" << std::endl;
}

void	HumanB::attack()
{
	std::cout << "HumanB " << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << "HumanB " << this->name << " is armed with a " << this->weapon->getType() << std::endl;
}
