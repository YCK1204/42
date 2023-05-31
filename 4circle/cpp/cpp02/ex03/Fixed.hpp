/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:05:50 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/18 19:57:02 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
	Fixed	operator + (Fixed fixed) const;
	Fixed	operator - (Fixed fixed) const;
	Fixed	operator * (Fixed fixed) const;
	Fixed	operator / (Fixed fixed) const;
	~Fixed();
	Fixed	&operator ++ ();
	Fixed	operator ++ (int);
	bool	operator > (Fixed fixed) const;
	bool	operator < (Fixed fixed) const;
	bool	operator >= (Fixed fixed) const;
	bool	operator <= (Fixed fixed) const;
	bool	operator == (Fixed fixed) const;
	bool	operator != (Fixed fixed) const;
	float	toFloat(void) const;
	double	toDouble(void) const;
	int		toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif
