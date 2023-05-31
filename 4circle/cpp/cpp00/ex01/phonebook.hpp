/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:38:39 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/22 21:03:16 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

class phoneBook
{
private:
	contact book[8];
public:
	void	getBook(std::string cmd, int *i);
};

bool	isInt(std::string str);
void	cinStr(std::string *cmd);

#endif
