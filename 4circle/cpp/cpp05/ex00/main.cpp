/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:27:26 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 21:27:27 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;
	Bureaucrat b("b", 0);
	Bureaucrat c("c", -1);
	Bureaucrat d("d", 150);
	Bureaucrat e("e", 151);

	std::cout << "=====================================" << std::endl;
	b.increaseGrade(1);
	std::cout << b.getName() + " : " << b.getGrade() << std::endl;
	d.decreaseGrade(1);
	std::cout << d.getName() + " : " << d.getGrade() << std::endl;
	e.decreaseGrade(1);
	std::cout << e.getName() + " : " << e.getGrade() << std::endl;

	std::cout << "=====================================" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
}
