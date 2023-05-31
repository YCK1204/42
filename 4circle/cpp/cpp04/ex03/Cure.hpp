/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:05:20 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/19 11:26:03 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &c);
	Cure &operator = (const Cure &c);
	~Cure();
	Cure(std::string const & type);
	std::string const & getType() const;
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
