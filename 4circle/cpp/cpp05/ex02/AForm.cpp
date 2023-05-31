/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:18:22 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:28:32 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : requiredToSign(1), requiredToExecute(1)
{
	this->Signed = false;
}

AForm::AForm(const std::string name, const bool beSigned, const int toSign, const int ToExecute) : name(name), requiredToSign(toSign), requiredToExecute(ToExecute)
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

AForm::AForm(const AForm &f) : name(f.name), requiredToSign(f.requiredToSign), requiredToExecute(f.requiredToExecute)
{
	*this = f;
}

AForm &AForm::operator = (const AForm &f)
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

AForm::~AForm() {}

void	AForm::beSigned(const Bureaucrat &b)
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

bool	AForm::getSign() const { return (this->Signed); }

std::string	AForm::getName() const { return (this->name); }

int			AForm::getToSign() const { return (this->requiredToSign); }

int			AForm::getToExecute() const { return (this->requiredToExecute); }

const char	*AForm::GradeTooHighException::what() const throw() { return ("Error: Too High Grade!"); }

const char	*AForm::GradeTooLowException::what() const throw() { return ("Error: Too Low Grade!"); }

std::ostream &operator << (std::ostream &os, const AForm &f)
{
	os << f.getName() + ", AForm beSigned " << f.getSign() << ", AForm required to Sign " << f.getToSign() << ", AForm required to Execute " << f.getToExecute();
	return (os);
}
