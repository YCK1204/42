/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:54:44 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/26 00:35:09 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	phoneBook::getBook(std::string cmd, int *i)
{
	int	idx;
	std::string tmp;

	if (!cmd.compare("ADD"))
	{
		this->book[*i % 8].ADD(i);
		*i += 1;
	}
	else if (!cmd.compare("SEARCH"))
	{
		std::cout << std::setw(10);
		std::cout << "Index|";
		std::cout << std::setw(10);
		std::cout << "First Name|";
		std::cout << std::setw(10);
		std::cout << " Last Name|";
		std::cout << std::setw(10);
		std::cout << " Nick Name" << std::endl;
		for (int k = 0; k < *i && k < 8; k++)
			this->book[k].SEARCH(&k);
		std::cout << "Index : ";
		std::cin >> tmp;
		if (std::cin.eof())
			exit(0);
		std::cin.clear();
		std::cin.ignore(2147483647, '\n');
		idx = std::atoi(tmp.c_str());
		if (isInt(tmp))
		{
			if (idx < 0 || idx > 7)
				std::cerr << "Wrong Index (0 ~ 7)" << std::endl;
			else if (idx > *i - 1)
			{
				std::cerr << "This is the index before being inserted" << std::endl;
				return ;
			}
			else
				this->book[idx].printInfo(idx);
		}
		else
			std::cerr << "It's not Int" << std::endl;
	}
	else
		std::cerr << "Wrong cmd (ADD, SEARCH, EXIT)" << std::endl;
}
