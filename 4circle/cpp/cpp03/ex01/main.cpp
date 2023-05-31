/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:26:21 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/30 17:14:50 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap a("a");
	ClapTrap b("b");
	ScavTrap aa("aa");
	ScavTrap bb("bb");

	a.attack("!~@#!$#%@#@");
	b.attack("!~@#!$#%@#@");
	aa.attack("!~@#!$#%@#@");
	bb.attack("!~@#!$#%@#@");

	a.takeDamage(20);
	b.takeDamage(5);
	aa.takeDamage(30);
	bb.takeDamage(500000);

	a.beRepaired(1000);
	b.beRepaired(1000);
	aa.beRepaired(1000);
	bb.beRepaired(1000);

	aa.guardGate();
	bb.guardGate();
	return (0);
}
