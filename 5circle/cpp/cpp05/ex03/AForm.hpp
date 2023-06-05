/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:18:19 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:18:20 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string	name;
	bool				Signed;
	const int			requiredToSign;
	const int			requiredToExecute;
public:
	AForm();
	AForm(const std::string name, const bool beSigned, const int toSign, const int ToExecute);
	AForm(const AForm &f);
	AForm &operator = (const AForm &f);
	virtual ~AForm();
	void		beSigned(const Bureaucrat &b);
	bool		getSign() const;
	std::string	getName() const;
	int			getToSign() const;
	int			getToExecute() const;
	virtual void	execute(Bureaucrat const & executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator <<(std::ostream &os, const AForm &f);
#endif
