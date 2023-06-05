/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:41:58 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/24 14:46:47 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *arr, size_t size, void (*f)(T&))
{
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

template <typename T>
void	print(T &v)
{
	std::cout << v << std::endl;
}
#endif
