/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:27:42 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 21:27:44 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("a", 75);
	Bureaucrat b("b", 100);
	Bureaucrat c("c", 30);
	Bureaucrat d("d", 5);
	Form	aa("aa", false, 90, 80);
	Form	bb("bb", false, 100, 80);
	Form	cc("cc", false, 31, 80);
	Form	dd("dd", false, 0, 80);

	std::cout << "===============================================" << std::endl;
	aa.beSigned(a);
	bb.beSigned(b);
	cc.beSigned(c);
	dd.beSigned(d);
	std::cout << "===============================================" << std::endl;

	a.signForm(aa);
	b.signForm(bb);
	c.signForm(cc);
	d.signForm(dd);
	std::cout << "===============================================" << std::endl;

	std::cout << aa << std::endl;
	std::cout << bb << std::endl;
	std::cout << cc << std::endl;
	std::cout << dd << std::endl;
}
