/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:32:05 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/15 18:39:05 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include "Base.hpp"

class B : public Base
{
private:
	B(const B &b);
	B &operator = (const B &b);
public:
	B();
	~B();
};

#endif
