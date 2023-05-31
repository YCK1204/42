/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:55:15 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/17 19:55:16 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->separator[0] = "DEBUG";
	this->separator[1] = "INFO";
	this->separator[2] = "WARNING";
	this->separator[3] = "ERROR";
}

Harl::~Harl()
{

}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cerr << "[ ERROR ]" << std::endl;
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;

	for(i = 0; i < 4 && this->separator[i] != level; i++);
	switch	(i)
	{
		case	0:			this->debug();
		case	1:			this->info();
		case	2:			this->warning();
		case	3:			this->error();break ;
		default:			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
