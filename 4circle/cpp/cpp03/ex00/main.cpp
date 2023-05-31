/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:26:21 by yeckim            #+#    #+#             */
/*   Updated: 2023/01/30 15:40:38 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("42");
	ClapTrap b("24");

	a.attack("24");
	b.takeDamage(2);
	b.beRepaired(10);
	b.attack("42");
	a.takeDamage(50);
	a.beRepaired(1000);

	return (0);
}
