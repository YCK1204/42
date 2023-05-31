/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:25:27 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/02 03:21:40 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string	name;
	int	hitPoint;
	int	energyPoint;
	int	attackDamage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap &c);
	ClapTrap(std::string name);
	ClapTrap &operator = (const ClapTrap &c);
	virtual ~ClapTrap();
	void	attack(const std::string& target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
};

#endif
