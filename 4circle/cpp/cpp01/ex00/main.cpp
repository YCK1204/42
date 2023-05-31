/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:33:51 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/12 16:27:54 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	z1("z1 (stack)");
	Zombie	*z2 = newZombie("z2 (heap)");

	randomChump("z3 (stack)");
	z1.announce();
	z2->announce();
	delete	z2;
	return (0);
}
