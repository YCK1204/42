/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:28:03 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/14 13:56:05 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm	*Intern::makeForm(const std::string name, const std::string type)
{
	std::string	types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int		i = 0;
	AForm	*ret;
	ShrubberyCreationForm	a;
	RobotomyRequestForm		b;
	PresidentialPardonForm	c;

	for (; i < 3 && types[i].compare(type); i++);
	switch (i)
	{
		case 0: ret = a.clone(type); std::cout << "Intern creates ShrubberyCreationForm" << std::endl; break;
		case 1: ret = b.clone(type); std::cout << "Intern creates RobotomyRequestForm" << std::endl; break;
		case 2: ret = c.clone(type); std::cout << "Intern creates PresidentialPardonForm" << std::endl; break;
		default: ret = NULL; std::cerr << "no matching type (" + type + ")" << std::endl; break;
	}
	return (ret);
}
