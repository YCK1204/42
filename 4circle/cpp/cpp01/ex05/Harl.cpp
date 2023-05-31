/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:54:59 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/17 19:55:02 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->separator[0] = "debug";
	this->separator[1] = "info";
	this->separator[2] = "warning";
	this->separator[3] = "error";
}

Harl::~Harl()
{

}

void	Harl::debug()
{
	std::cout << "debug message" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "info message" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "warning message" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cerr << "error message" << std::endl;
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;

	for(; i < 4 && this->separator[i].compare(level); i++);
	switch	(i)
	{
		case	0:			this->debug();	break ;
		case	1:			this->info();	break ;
		case	2:			this->warning();break ;
		case	3:			this->error();	break ;
		default:			std::cerr << "Error : level not found(level : " << level << ")" << std::endl;
	}
}
