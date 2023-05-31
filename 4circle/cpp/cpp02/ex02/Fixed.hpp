/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:05:50 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/14 10:17:13 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	const  static int	bits = 8;
public:
	Fixed();
	Fixed(int v);
	Fixed(const float v);
	Fixed &operator = (const Fixed &fixed);
	static Fixed	&max(Fixed &a, Fixed &b);
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&max(Fixed const &a, Fixed const &b);
	static const Fixed	&min(Fixed const &a, Fixed const &b);
	~Fixed();
	Fixed	&operator ++ ();
	Fixed	operator ++ (int);
	Fixed	&operator -- ();
	Fixed	operator -- (int);
	Fixed	operator + (Fixed fixed) const;
	Fixed	operator - (Fixed fixed) const;
	Fixed	operator * (Fixed fixed) const;
	Fixed	operator / (Fixed fixed) const;
	bool	operator > (Fixed fixed) const;
	bool	operator < (Fixed fixed) const;
	bool	operator >= (Fixed fixed) const;
	bool	operator <= (Fixed fixed) const;
	bool	operator == (Fixed fixed) const;
	bool	operator != (Fixed fixed) const;
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif
