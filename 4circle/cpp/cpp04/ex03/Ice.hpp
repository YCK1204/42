/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:03:33 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/19 01:00:19 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &i);
	Ice &operator = (const Ice &i);
	~Ice();
	Ice(std::string const & type);
	std::string const & getType() const;
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
