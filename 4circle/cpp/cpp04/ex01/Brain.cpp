/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:57:48 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 14:40:23 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = b;
}

Brain &Brain::operator = (const Brain &b)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	std::cout << "Brain Copy assignment Constructor called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

std::string	Brain::getIdea(int idx) const
{
	return (this->ideas[idx]);
}

void	Brain::setIdea(const std::string str, int idx)
{
	this->ideas[idx] = str;
}
