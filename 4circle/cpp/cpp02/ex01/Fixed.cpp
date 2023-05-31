/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:49:27 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/14 07:05:36 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int v)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = v << this->bits;
}

Fixed::Fixed(const float v)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = static_cast<int>(roundf(v * (1 << this->bits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.value;
	return (*this);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << this->bits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}
