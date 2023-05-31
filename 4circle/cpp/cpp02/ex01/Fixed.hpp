/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:05:50 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/14 06:54:25 by yeckim           ###   ########.fr       */
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
	const static int	bits = 8;
public:
	Fixed();
	Fixed(const int v);
	Fixed(const float v);
	Fixed(const Fixed &fixed);
	Fixed &operator = (const Fixed &fixed);
	~Fixed();
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);
#endif
