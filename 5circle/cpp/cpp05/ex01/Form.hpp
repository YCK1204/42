/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:27:38 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 21:27:40 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				Signed;
	const int			requiredToSign;
	const int			requiredToExecute;
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
public:
	Form();
	Form(const std::string name, const bool beSigned, const int toSign, const int ToExecute);
	Form(const Form &f);
	Form &operator = (const Form &f);
	~Form();
	void		beSigned(const Bureaucrat &b);
	bool		getSign() const;
	std::string	getName() const;
	int			getToSign() const;
	int			getToExecute() const;
};

std::ostream &operator <<(std::ostream &os, const Form &f);
#endif
