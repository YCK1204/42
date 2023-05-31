/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:18:09 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/14 13:56:09 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* rrf1;
	AForm* rrf2;
	AForm* rrf3;
	AForm* rrf4;

	rrf = someRandomIntern.makeForm("Bender", "robotomy request");
	rrf1 = someRandomIntern.makeForm("jhon", "shrubbery creation");
	rrf2 = someRandomIntern.makeForm("bob", "presidential pardon");
	rrf3 = someRandomIntern.makeForm("jimi", "hello world!");

	std::cout << *rrf << std::endl;
	std::cout << *rrf1 << std::endl;
	std::cout << *rrf2 << std::endl;

	delete rrf;
	delete rrf1;
	delete rrf2;
	delete rrf3;
	return (0);
}
