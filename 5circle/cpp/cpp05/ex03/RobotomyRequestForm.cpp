/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:17:55 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:48:18 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	int			*tmp1 = const_cast<int*>(&this->requiredToSign);
	int			*tmp2 = const_cast<int*>(&this->requiredToExecute);

	*tmp1 = 72;
	*tmp2 = 45;
	this->Signed = false;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const bool Sign, const int ToSign, const int ToExecute)
{
	std::string	*tmp = const_cast<std::string*>(&this->name);
	int			*tmp1 = const_cast<int*>(&this->requiredToSign);
	int			*tmp2 = const_cast<int*>(&this->requiredToExecute);

	*tmp = name;
	*tmp1 = ToSign;
	*tmp2 = ToExecute;
	this->Signed = Sign;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s)
{
	*this = s;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &s)
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

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	grade = executor.getGrade();
	std::srand(std::time(NULL));
	if (this->Signed)
	{
		if (grade <= this->requiredToExecute)
		{
			std::cout << "Drilzzzzzzzzzzzzzzzzzzzz.............." << std::endl;
			if (std::rand() % 2)
			{
				std::cout << "successfully " + executor.getName() + " has been robotomized" << std::endl;
				std::cout << executor.getName() + " executed " + this->name << std::endl;
			}
			else
				std::cout << executor.getName() + " failed" << std::endl;
		}
		else
			std::cerr << executor.getName() + " not enough grade" << std::endl;
	}
	else
		std::cerr << this->name + " before being beSigned" << std::endl;
}

RobotomyRequestForm	*RobotomyRequestForm::clone(const std::string name) { return (new RobotomyRequestForm(name, false, 72, 45)); }
