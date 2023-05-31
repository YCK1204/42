/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:27:34 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 21:27:35 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, const int grade);
	Bureaucrat(const Bureaucrat &b);
	Bureaucrat &operator = (const Bureaucrat &b);
	~Bureaucrat();
	std::string getName() const;
	int			getGrade() const;
	void		increaseGrade(const int val);
	void		decreaseGrade(const int val);
	void		signForm(const Form &f);
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &b);

#endif
