/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:47:30 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/16 00:52:36 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Except.hpp"

Base* generate() 
{
	int r = std::rand() % 3;
	switch (r)
	{
		case 0 : return (new A());
		case 1 : return (new B());
		case 2 : return (new C());
	}
	return (NULL);
}

void identify(Base* p) 
{
	if (dynamic_cast<A*>(p))
		std::cout << "* : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "* : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "* : C" << std::endl;
	else
		std::cerr << "* no matching class" << std::endl;
}

void identify(Base &p) 
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "& : A" << std::endl;
	}
	catch (std::exception &e) {static_cast<void>(e);}
	try
	{
		B &b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "& : B" << std::endl;
	}
	catch (std::exception &e) {static_cast<void>(e);}
	try
	{
		C &c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "& : C" << std::endl;
	}
	catch (std::exception &e) {	static_cast<void>(e);}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int	status = 0;

	Base *ptr[10];

	for (int i = 0; i < 10; i++)
		ptr[i] = NULL;
	try
	{
		for (int i = 0; i < 10; i++)
		{
			ptr[i] = generate();
			if (ptr[i] == NULL)
				throw Except::eption();
			identify(ptr[i]);
			identify(*ptr[i]);
			std::cout << "========================================" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		status = 1;
	}
	for (int i = 0; i < 10 && ptr[i]; i++)
		delete ptr[i];
	return (status);
}
