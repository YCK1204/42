/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 04:52:56 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/19 16:40:57 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main()
{
	MutantStack<int> mstack;
	std::list<int>   lst;
	mstack.push(5);
	mstack.push(17);
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "stack : " << mstack.top() << std::endl;
	std::cout << "list : " << lst.back() << std::endl;
	mstack.pop();
	lst.pop_back();
	std::cout << "stack : " << mstack.size() << std::endl;
	std::cout << "list : " << lst.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	mstack.push(0);
	lst.push_back(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator itt = lst.begin();
	std::list<int>::iterator itte = lst.end();

	++it;
	--it;
	++itt;
	--itt;
	while (it != ite)
	{
		std::cout << "stack : " << *it << std::endl;
		++it;
	}
	while (itt != itte)
	{
		std::cout << "list : " << *itt << std::endl;
		++itt;
	}
	std::stack<int> s(mstack);

	MutantStack<int> mstack1 = mstack;
	std::list<int> sssss = lst;
	mstack1.push(123456);
	mstack1.push(123456123);
	sssss.push_back(123456);
	sssss.push_back(123456123);
	std::cout << "stack : ";
	for (MutantStack<int>::iterator iter = mstack1.begin(); iter != mstack1.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "stack : ";
	for (MutantStack<int>::iterator iter = mstack.begin(); iter != mstack.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "list : "; 
	for (std::list<int>::iterator iter = sssss.begin(); iter != sssss.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "list : "; 
	for (std::list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	return 0;
}
