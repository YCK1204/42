/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:55:17 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/17 19:55:19 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>

class	Harl
{
private:
	std::string	separator[4];
	void		debug();
	void		info();
	void		warning();
	void		error();
public:
	Harl();
	~Harl();
	void	complain(std::string level);
};
#endif
