/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:54:30 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/18 17:11:56 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char *noSuchElementException::what() const throw ()
{
	return ("Error: No Such Element");
}

int main()
{
	int vals[5] = {2, 2147483647, -1, 0, 1};
	std::vector<int> arr1(vals, vals + 5);
	std::deque<int> arr2(vals, vals + 5);
	std::list<int> arr3(vals, vals + 5);
	for (int i = 0; i < 5; i++)
	{
		arr1.push_back(vals[i]);
		arr2.push_back(vals[i]);
		arr3.push_back(vals[i]);
	}
	try
	{
		std::vector<int>::iterator tmp = easyfind(arr1, -1);
		std::cout << "search for -1 in vector";
		std::cout << ", tmp : " << *tmp << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::deque<int>::iterator tmp = easyfind(arr2, 321);
		std::cout << "search for 321 in deque";
		std::cout << ", tmp : " << *tmp << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator tmp = easyfind(arr3, 2147483647);
		std::cout << "search for 2147483647 in list";
		std::cout << ", tmp : " << *tmp << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
