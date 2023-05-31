/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:26:21 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/30 19:07:21 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("a");
	ClapTrap b("b");
	FragTrap c("c");
	ScavTrap d("d");

	a.whoAmI();
	a.attack("b");
	b.attack("c");
	c.attack("d");
	d.attack("e");
	a.highFivesGuys();
	c.highFivesGuys();
	d.guardGate();

	return (0);
}
