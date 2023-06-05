/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:34:16 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/16 20:59:47 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b) 
{
	T temp = a;
	a = b;
	b = temp;
}
template<typename T>
T min(const T& a, const T& b) 
{
	return (b <= a) ? b : a;
}
template<typename T>
T max(const T& a, const T& b) 
{
	return (a <= b) ? b : a;
}
#endif
