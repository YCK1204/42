/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Except.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:42:12 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/15 23:42:10 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPT_HPP
# define EXCEPT_HPP

#include <iostream>

class Except
{
private:
	Except();
	Except(const Except &e);
	Except &operator = (const Except &e);
public:
	~Except();
	class eption : public std::exception
	{
		const char *what() const throw();
	};
};

#endif
