/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:57:24 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/12 19:53:56 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << "HumanA " << this->name << " was created and he is armed with a " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->name << " is dead" << std::endl;
}

void	HumanA::attack()
{
	std::cout << "HumanA " << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
	std::cout << "HumanA " << this->name << " is armed with a " << this->weapon.getType() << std::endl;
}
