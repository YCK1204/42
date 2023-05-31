/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:35:01 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/02 03:24:33 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &c);
	DiamondTrap(std::string name);
	DiamondTrap &operator = (const DiamondTrap &c);
	~DiamondTrap();
	void	whoAmI();
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
