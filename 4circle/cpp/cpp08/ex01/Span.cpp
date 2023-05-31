/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:13:58 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/19 15:39:32 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->size = 0;
}

Span::Span(unsigned int N)
{
	this->size = N;
}

Span::Span(const Span &s)
{
	*this = s;
}

Span &Span::operator = (const Span &s)
{
	if (this != &s)
	{
		this->size = s.size;
		this->arr = s.arr;
	}
	return (*this);
}

Span::~Span()
{
}

unsigned int	Span::getSize()
{
	return (this->size);
}

void	Span::addNumber(int n)
{
	try
	{
		if (this->arr.size() >= this->size)
			throw isFullArrayException();
		this->arr.push_back(n);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

unsigned int		Span::shortestSpan()
{
	unsigned int	ret = INF;

	if (this->arr.empty())
		throw isEmptyArrayException();
	else if (this->arr.size() == 1)
		throw invalidArgumentException();
	std::sort(this->arr.begin(), this->arr.end());
	for (std::vector<int>::iterator it = this->arr.begin() + 1; it != this->arr.end(); it++)
	{
		if (static_cast<unsigned int>(*it - *(it - 1)) < ret)
			ret = *it - *(it - 1);
	}
	return (ret);
}

unsigned int		Span::longestSpan()
{
	if (this->arr.empty())
		throw isEmptyArrayException();
	else if (this->arr.size() == 1)
		throw invalidArgumentException();
	std::sort(this->arr.begin(), this->arr.end());
	return (static_cast<unsigned int>(*(this->arr.end() - 1) - *(this->arr.begin())));
}

const char *Span::isFullArrayException::what() const throw()
{
	return ("Array is Full!");
}

const char *Span::isEmptyArrayException::what() const throw()
{
	return ("Array is Empty!");
}

const char 	*Span::invalidArgumentException::what() const throw()
{
	return ("Array size is too Small!");
}
