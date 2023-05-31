/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:05:52 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/19 15:34:09 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

# define INF 4294967295

class Span
{
private:
	std::vector<int> arr;
	unsigned int	size;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &s);
	Span &operator = (const Span &s);
	~Span();
	unsigned int	getSize();
	void	addNumber(int n);
	unsigned int		shortestSpan();
	unsigned int		longestSpan();
	class isFullArrayException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class isEmptyArrayException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class invalidArgumentException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
