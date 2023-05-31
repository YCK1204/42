/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:15:27 by yeckim            #+#    #+#             */
/*   Updated: 2023/01/31 20:15:29 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << this->type << " was created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << this->type << " was destroyed" << std::endl;
}

const	std::string	&Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(const std::string type)
{
	std::string prev_weapon = this->type;
	this->type = type;
	std::cout << "Reset weapon \"" << prev_weapon << "\"(before) -> \"" << this->type << "\"(after)" << std::endl;
}
