/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:27:31 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 21:27:32 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {this->grade = 1;}

Bureaucrat::Bureaucrat(const Bureaucrat &b) {*this = b;}

Bureaucrat::Bureaucrat(std::string name, const int grade) : name(name)
{
	this->grade = grade;
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &b)
{
	std::string	*tmp = const_cast<std::string*>(&this->name);
	if (this != &b)
	{
		*tmp = b.name;
		this->grade = b.grade;
		try
		{
			if (b.grade < 1)
				throw GradeTooHighException();
			else if (b.grade > 150)
				throw GradeTooLowException();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::increaseGrade(const int val)
{
	try
	{
		if (this->grade - val < 1)
			throw GradeTooHighException();
		this->grade -= val;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void		Bureaucrat::decreaseGrade(const int val)
{
	try
	{
		if (this->grade + val > 150)
			throw GradeTooLowException();
		this->grade += val;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void		Bureaucrat::signForm(const Form &f)
{
	std::string	reason;

	if (f.getSign())
		std::cout << this->name + " signed " + f.getName() << std::endl;
	else
	{
		if (this->grade < 1)
			reason = "Grade Too High";
		else if (this->grade > 150)
			reason = "Grade Too Low";
		else
			reason = "before being beSigned";
		std::cerr << this->name + " couldn’t sign " + f.getName() + " because " + reason << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Too High Grade!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Too Low Grade!");
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() + ", bureaucrat grade " << b.getGrade();
	return (os);
}
