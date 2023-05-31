/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:44:45 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 15:53:09 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() 
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &c)
{
	this->name = c.name;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (c.inventory[j])
				this->inventory[i] = c.inventory[j];
			else
				this->inventory[i] = NULL;
		}
	}
}

Character &Character::operator = (const Character &c)
{
	if (this != &c)
	{
		this->name = c.name;
		for (int i = 0; i < 4; i++)
			this->inventory[i] = c.inventory[i];
	}
	return (*this);
}

Character::~Character() {}

std::string	const &Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	int	i;
	int	f;

	if (m)
	{
		for (i = 0; i < 4; i++)
			if (!this->inventory[i])
				break ;
		for (int j = 0; j < 4 && i < 4; j++)
		{
			f = 1;
			for (int k = 0; k < 4; k++)
			{
				if (!this->inventory[k])
					continue ;
				if (!this->inventory[k]->getType().compare(m->getType()))
					f = 0;
			}
			if (f)
			{
				this->inventory[i++] = m;
				break ;
			}
		}
	}
	else
		std::cout << "not found skill type" << std::endl;
}

void	Character::unequip(int idx)
{
	if (0 <= idx && idx < 4 && this->inventory[idx])
		this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx < 4)
	{
		if (this->inventory[idx])
		{
			if (!this->inventory[idx]->getType().compare("ice") || !this->inventory[idx]->getType().compare("cure"))
				this->inventory[idx]->use(target);
		}
	}
}
