/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:47:03 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/30 17:11:36 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public :
	FragTrap();
	FragTrap(const FragTrap &c);
	FragTrap(std::string name);
	FragTrap &operator = (const FragTrap &c);
	~FragTrap();
	void	highFivesGuys(void);
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
#endif
