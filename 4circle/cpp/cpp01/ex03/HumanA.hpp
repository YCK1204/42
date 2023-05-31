/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:44:13 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/12 19:53:48 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon		&weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack();
	void	setWeapon(Weapon &weapon);
};
#endif
