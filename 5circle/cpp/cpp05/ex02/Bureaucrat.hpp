/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:18:12 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:18:13 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

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
	void		signForm(const AForm &f);
	void	executeForm(AForm const & Aform);
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
