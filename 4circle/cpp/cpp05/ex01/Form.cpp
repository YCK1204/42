/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:27:35 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 21:27:38 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : requiredToSign(1), requiredToExecute(1)
{
	this->Signed = false;
}

Form::Form(const std::string name, const bool beSigned, const int toSign, const int ToExecute) : name(name), requiredToSign(toSign), requiredToExecute(ToExecute)
{
	this->Signed = beSigned;
	try
	{
		if (toSign < 1 || ToExecute < 1)
			throw GradeTooHighException();
		else if (toSign > 150 || ToExecute > 150)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(const Form &f) : name(f.name), requiredToSign(f.requiredToSign), requiredToExecute(f.requiredToExecute)
{
	*this = f;
}

Form &Form::operator = (const Form &f)
{
	std::string	*tmp = const_cast<std::string*>(&f.name);
	int			*tmp1 = const_cast<int*>(&f.requiredToSign);
	int			*tmp2 = const_cast<int*>(&f.requiredToExecute);

	if (this != &f)
	{
		this->Signed = f.Signed;
		*tmp = f.name;
		*tmp1 = f.requiredToSign;
		*tmp2 = f.requiredToExecute;
		try
		{
			if (this->requiredToSign < 1 || this->requiredToExecute < 1)
				throw GradeTooHighException();
			else if (this->requiredToSign > 150 || this->requiredToExecute > 150)
				throw GradeTooLowException();
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (*this);
}

Form::~Form() {}

void	Form::beSigned(const Bureaucrat &b)
{
	try
	{
		if (b.getGrade() < 1)
			throw GradeTooHighException();
		else if (b.getGrade() > 150)
			throw GradeTooLowException();
		else if (b.getGrade() <= this->requiredToSign)
			this->Signed = true;
		else
			std::cout << b.getName() << " Grade not enough" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed beSigned " << e.what() << std::endl;
	}
}

bool	Form::getSign() const { return (this->Signed); }

std::string	Form::getName() const { return (this->name); }

int			Form::getToSign() const { return (this->requiredToSign); }

int			Form::getToExecute() const { return (this->requiredToExecute); }

const char	*Form::GradeTooHighException::what() const throw() { return ("Error: Too High Require Grade!"); }

const char	*Form::GradeTooLowException::what() const throw() { return ("Error: Too Low Require Grade!"); }

std::ostream &operator << (std::ostream &os, const Form &f)
{
	os << f.getName() + ", Form beSigned " << f.getSign() << ", Form required to Sign " << f.getToSign() << ", Form required to Execute " << f.getToExecute();
	return (os);
}
