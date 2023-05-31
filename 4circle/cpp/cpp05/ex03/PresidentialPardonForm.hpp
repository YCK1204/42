/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:17:51 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:45:17 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string name, const bool Sign, const int ToSign, const int ToExecute);
	PresidentialPardonForm(const PresidentialPardonForm &s);
	PresidentialPardonForm &operator = (const PresidentialPardonForm &r);
	~PresidentialPardonForm();
	void	execute(Bureaucrat const & executor) const;
	PresidentialPardonForm	*clone(const std::string name);
};

#endif
