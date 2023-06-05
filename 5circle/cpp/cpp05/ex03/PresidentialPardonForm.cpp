/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:17:47 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:47:03 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	int			*tmp1 = const_cast<int*>(&this->requiredToSign);
	int			*tmp2 = const_cast<int*>(&this->requiredToExecute);

	*tmp1 = 25;
	*tmp2 = 5;
	this->Signed = false;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name, const bool Sign, const int ToSign, const int ToExecute)
{
	std::string	*tmp = const_cast<std::string*>(&this->name);
	int			*tmp1 = const_cast<int*>(&this->requiredToSign);
	int			*tmp2 = const_cast<int*>(&this->requiredToExecute);

	*tmp = name;
	*tmp1 = ToSign;
	*tmp2 = ToExecute;
	this->Signed = Sign;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s) 
{
	*this = s;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &s)
{
	std::string	*tmp = const_cast<std::string*>(&this->name);
	int			*tmp1 = const_cast<int*>(&this->requiredToSign);
	int			*tmp2 = const_cast<int*>(&this->requiredToExecute);

	if (this != &s)
	{
		this->Signed = s.Signed;
		*tmp = s.name;
		*tmp1 = s.requiredToSign;
		*tmp2 = s.requiredToExecute;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	int	grade = executor.getGrade();
	if (this->Signed)
	{
		if (grade <= this->requiredToExecute)
		{
			std::cout << executor.getName() + " has been pardoned by Zaphod Beeblebrox." << std::endl;
			std::cout << executor.getName() + " executed " + this->name << std::endl;
		}
		else
			std::cerr << executor.getName() + " not enough grade" << std::endl;
	}
	else
		std::cerr << this->name + " before being beSigned" << std::endl;
}

PresidentialPardonForm	*PresidentialPardonForm::clone(const std::string name) { return (new PresidentialPardonForm(name, false, 25, 5)); }
