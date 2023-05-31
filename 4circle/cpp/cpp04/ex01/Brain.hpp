/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:38:55 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 14:39:38 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain 
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &b);
	Brain &operator = (const Brain &b);
	~Brain();
	std::string	getIdea(int idx) const;
	void	setIdea(const std::string str, int idx);
};

#endif
