/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:31:13 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/15 18:39:12 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class C : public Base
{
private:
	C(const C &c);
	C &operator = (const C &c);
public:
	C();
	~C();
};

#endif
