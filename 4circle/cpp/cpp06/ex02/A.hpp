/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:30:19 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/15 23:51:01 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class A : public Base
{
private:
	A(const A &a);
	A &operator = (const A &a);
public:
	A();
	~A();
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
