/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:33:51 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/11 19:38:27 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1("z1 (stack)");
	Zombie	*zs = zombieHorde(10, "zombies(heap)");

	z1.announce();
	for(int i = 0; i < 10; i++)
		zs[i].announce();
	delete [] zs;
	return (0);
}
