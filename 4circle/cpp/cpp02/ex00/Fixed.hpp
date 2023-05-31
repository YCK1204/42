/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:05:50 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/13 18:49:58 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					value;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator = (const Fixed &fixed);
	~Fixed();
	int	getRawBits() const;
	void	setRawBits(int const raw);
};

#endif
