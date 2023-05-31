/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:49:27 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/14 10:18:16 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(int v)
{
	this->value = v << this->bits;
}

Fixed::Fixed(const float v)
{
	this->value = static_cast<int>(roundf(v * (1 << this->bits)));
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator ++ ()
{
	++this->value;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	tmp(*this);

	this->value++;
	return (tmp);
}

Fixed	&Fixed::operator -- ()
{
	--this->value;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	tmp(*this);

	this->value--;
	return (tmp);
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.value;
	return (*this);
}

Fixed	Fixed::operator + (Fixed const fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator - (Fixed const fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator * (Fixed const fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator / (Fixed const fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator > (Fixed fixed) const
{
	return (this->value > fixed.value);
}

bool	Fixed::operator < (Fixed fixed) const
{
	return (this->value < fixed.value);
}

bool	Fixed::operator >= (Fixed fixed) const
{
	return (this->value >= fixed.value);
}

bool	Fixed::operator <= (Fixed fixed) const
{
	return (this->value <= fixed.value);
}

bool	Fixed::operator == (Fixed fixed) const
{
	return (this->value == fixed.value);
}

bool	Fixed::operator != (Fixed fixed) const
{
	return (this->value != fixed.value);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << this->bits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}
