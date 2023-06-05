/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:25:17 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/19 15:42:58 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	///////////////////////////////////
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	//////////////////////////////////
	std::cout << "============================" << std::endl;
	
	Span Sp = Span(2);
	Sp.addNumber(-2147483648);
	Sp.addNumber(2147483647);
	Sp.addNumber(2147483647);
	std::cout << Sp.shortestSpan() << std::endl;
	std::cout << Sp.longestSpan() << std::endl;

	Span SP = Span(10);
	try
	{
		std::cout << SP.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	SP.addNumber(2147483647);
	try
	{
		std::cout << SP.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	SP.addNumber(2147483647);
	try
	{
		std::cout << SP.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
