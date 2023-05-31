/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:25:02 by yeckim            #+#    #+#             */
/*   Updated: 2023/01/19 16:21:40 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie(std::string name);
	void	announce();
	~Zombie();
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
