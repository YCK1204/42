/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:44:20 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/24 14:46:50 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int			arr1[5] = {2147483647, 1, 0, -1, -2147483648};
	std::string arr2[5] = {"hello", "world", "oh", "my", "god"};
	double		arr3[5] = {3.141592, -0, 0, 1.1, 1234.1234};
	std::cout << "int ===========================================" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "arr1[" << i << "] = " << arr1[i] << ", ";
	std::cout << std::endl;
	::iter(arr1, 5, print<int>);
	std::cout << "string ===========================================" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "arr2[" << i << "] = " << arr2[i] << ", ";
	std::cout << std::endl;
	::iter(arr2, 5, print<std::string>);
	std::cout << "double ===========================================" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "arr3[" << i << "] = "  << arr3[i] << ", ";
	std::cout << std::endl;
	::iter(arr3, 5, print<double>);
	return (0);
}
