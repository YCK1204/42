/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:52:40 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/23 21:45:00 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	cinStr(std::string *cmd)
{
	getline(std::cin, *cmd);
	if (std::cin.eof())
		exit(0);
}

bool	isInt(std::string str)
{
	size_t	len = str.length();

	for (int i = 0; i < len; i++)
		if ('0' > str[i] || str[i] > '9')
			return (0);
	return (1);
}

int	main()
{
	int			i = 0;
	std::string	cmd;
	phoneBook	book;

	while (1)
	{
		std::cout << "cmd : ";
		getline(std::cin, cmd);
		if (std::cin.eof() || !cmd.compare("EXIT"))
			break ;
		else
			book.getBook(cmd, &i);
	}
	return (0);
}
