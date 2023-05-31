/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:18:31 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/18 17:11:14 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>

class noSuchElementException : public std::exception
{
public:
	const char *what () const throw();
};

template <typename T>
typename T::iterator	easyfind(T &arr, int v)
{
	typename T::iterator iter = std::find(arr.begin(), arr.end(), v);
	if (iter == arr.end())
		throw noSuchElementException();
	return (iter);
}



#endif
