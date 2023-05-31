/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:47:03 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/02 03:24:20 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public :
	FragTrap();
	FragTrap(const FragTrap &c);
	FragTrap(std::string name);
	FragTrap &operator = (const FragTrap &c);
	virtual ~FragTrap();
	void	highFivesGuys(void);
	virtual void	attack(const std::string &target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
};
#endif
