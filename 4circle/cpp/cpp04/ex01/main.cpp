/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:57:29 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 16:25:41 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const int	SIZE = 10;
	Animal	*arr[SIZE];
	std::cout << "Constructor ========================================" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	std::cout << "Destructor =========================================" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete arr[i];
	std::cout << "====================================================" << std::endl;
	Dog	d;
	d.getBrain()->setIdea("hello Dog!", 0);
	Dog d1(d);
	d1.getBrain()->setIdea("Hi Dog!", 0);
	Cat c;
	c.getBrain()->setIdea("hello Cat!", 0);
	Cat c1(c);
	c1.getBrain()->setIdea("Hi Cat!", 0);
	std::cout << "====================================================" << std::endl;
	std::cout << "d : " + d.getBrain()->getIdea(0) << std::endl;
	std::cout << "d1 : " + d1.getBrain()->getIdea(0) << std::endl;
	std::cout << "c : " + c.getBrain()->getIdea(0) << std::endl;
	std::cout << "c1 : " + c1.getBrain()->getIdea(0) << std::endl;
	std::cout << "====================================================" << std::endl;
	return 0;
}
