/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:18:09 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:33:25 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat a("a", 75);
	Bureaucrat b("b", 100);
	Bureaucrat c("c", 30);
	Bureaucrat d("d", 5);
	Bureaucrat e("e", 40);

	ShrubberyCreationForm	aa("aa", false, 145, 137);
	RobotomyRequestForm	bb("bb", false, 72, 45);
	PresidentialPardonForm	cc("cc", false, 25, 5);
	PresidentialPardonForm	dd("dd", false, 25, 5);
	RobotomyRequestForm	ee("ee", false, 72, 45);
	std::cout << "===================================" << std::endl;
	aa.beSigned(a);
	bb.beSigned(b);
	cc.beSigned(c);
	dd.beSigned(d);
	ee.beSigned(e);
	std::cout << "===================================" << std::endl;

	a.executeForm(aa);
	b.executeForm(bb);
	c.executeForm(cc);
	d.executeForm(dd);
	e.executeForm(ee);
}
