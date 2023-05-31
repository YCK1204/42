/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Except.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:13:58 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/16 00:22:10 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Except.hpp"

Except::Except() {}
Except::Except(const Except &e) { *this = e; }
Except &Except::operator = (const Except &e)
{
	static_cast<void>(e);
	return (*this);
}
Except::~Except(){}

const char *Except::eption::what() const throw()
{
	return ("Error! cannot allocate memory");
}
