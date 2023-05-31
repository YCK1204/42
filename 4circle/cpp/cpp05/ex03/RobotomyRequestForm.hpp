/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:17:58 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:47:28 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>

class	RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string name, const bool Sign, const int ToSign, const int ToExecute);
	RobotomyRequestForm(const RobotomyRequestForm &s);
	RobotomyRequestForm &operator = (const RobotomyRequestForm &r);
	~RobotomyRequestForm();
	void	execute(Bureaucrat const & executor) const;
	RobotomyRequestForm	*clone(const std::string name);
};

#endif
