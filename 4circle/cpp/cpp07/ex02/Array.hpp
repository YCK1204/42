/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:33:12 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/16 19:36:56 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
template <typename T>
class Array
{
private:
	std::size_t	len;
	T *arr;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &a);
	Array &operator = (const Array &a);
	~Array();
	class outOfRangeException : public std::exception
	{
		const char *what() const throw();
	};
	T &operator[] (int idx);
	std::size_t	size() const;
};

#include "Array.tpp"
#endif
