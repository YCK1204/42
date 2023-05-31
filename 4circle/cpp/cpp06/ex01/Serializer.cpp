/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:04:04 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/16 00:23:18 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &s){*this = s;}
Serializer &Serializer::operator = (const Serializer &s)
{
	static_cast<void>(s);
	return (*this);
}
uintptr_t	Serializer::serialize(Data* ptr){return (reinterpret_cast<uintptr_t>(ptr));}
Data *Serializer::deserialize(uintptr_t raw){return (reinterpret_cast<Data *>(raw));}
