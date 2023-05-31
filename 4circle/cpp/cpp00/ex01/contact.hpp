/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:52:59 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/22 20:43:41 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class contact
{
private:
	std::string		firstName;
	std::string		lastName;
	std::string		nickName;
	std::string		phoneNum;
	std::string		secret;
public:
	void	ADD(int *i);
	void	SEARCH(int *i);
	void	printInfo(int idx);
};
#endif
