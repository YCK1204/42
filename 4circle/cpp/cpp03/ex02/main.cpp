/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:26:21 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/30 17:16:47 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap a("a");
	ScavTrap b("b");
	FragTrap c("c");

	a.attack("@!###$%");
	b.attack("@!###$%");
	c.attack("@!###$%");

	a.takeDamage(30);
	b.takeDamage(30);
	c.takeDamage(30);

	a.beRepaired(1000);
	b.beRepaired(1000);
	c.beRepaired(1000);

	c.highFivesGuys();
	return (0);
}
