/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:23:24 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/11 19:40:20 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "hello string!";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "print address" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "address of str               : " << &str << std::endl;
	std::cout << "address of stringREF         : " << &stringREF << std::endl;
	std::cout << "address of stringPTR         : " << stringPTR << std::endl;
	std::cout << "address of stringPTR pointer : " << &stringPTR << std::endl;

	std::cout << std::endl << "print value" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "value of str                 : " << str << std::endl;
	std::cout << "value of stringPTR           : " << *stringPTR << std::endl;
	std::cout << "value of stringREF           : " << stringREF << std::endl;
	return (0);
}
