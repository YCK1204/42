/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:02:16 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/15 21:10:00 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *before = new Data;
	before->Int = 1234;
	before->Char = '*';
	before->Float = 3.14;
	before->Double = 0.1;
	before->String = "hello";

	std::cout << "before Int          " << before->Int << std::endl;
	std::cout << "before Char         " << before->Char << std::endl;
	std::cout << "before Float        " << before->Float << std::endl;
	std::cout << "before Double       " << before->Double << std::endl;
	std::cout << "before String       " << before->String << std::endl;
	std::cout << "before address      " << before << std::endl;
	std::cout << "======================================" << std::endl;
	uintptr_t	tmp = Serializer::serialize(before);
	std::cout << tmp << std::endl;
	std::cout << "======================================" << std::endl;
	Data *after = Serializer::deserialize(tmp);
	std::cout << "after Int           " << after->Int << std::endl;
	std::cout << "after Char          " << after->Char << std::endl;
	std::cout << "after Float         " << after->Float << std::endl;
	std::cout << "after Double        " << after->Double << std::endl;
	std::cout << "after String        " << after->String << std::endl;
	std::cout << "after address       " << after << std::endl;
	delete before;

	return (0);
}
