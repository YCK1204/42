/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:21:17 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/19 13:34:56 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

AMateria::~AMateria() {}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
