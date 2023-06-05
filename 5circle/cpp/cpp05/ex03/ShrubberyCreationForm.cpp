/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:18:01 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:49:15 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	int			*tmp1 = const_cast<int*>(&this->requiredToSign);
	int			*tmp2 = const_cast<int*>(&this->requiredToExecute);

	*tmp1 = 145;
	*tmp2 = 137;
	this->Signed = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const bool Sign, const int ToSign, const int ToExecute)
{
	std::string	*tmp = const_cast<std::string*>(&this->name);
	int			*tmp1 = const_cast<int*>(&this->requiredToSign);
	int			*tmp2 = const_cast<int*>(&this->requiredToExecute);

	*tmp = name;
	*tmp1 = ToSign;
	*tmp2 = ToExecute;
	this->Signed = Sign;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) 
{
	*this = s;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &s)
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

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	outfile;
	int	grade = executor.getGrade();
	if (this->Signed)
	{
		if (grade <= this->requiredToExecute)
		{
			outfile.open(this->name + "_shrubbery");
			outfile << "                                                         .\n";
			outfile << "                                  .         ;\n";  
			outfile << "                 .              .              ;%     ;;\n";   
			outfile << "                   ,           ,                :;%  %;\n";   
			outfile << "                    :         ;                   :;%;'     .,\n";   
			outfile << "           ,.        %;     %;            ;        %;'    ,;\n";
			outfile << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
			outfile << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
			outfile << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
			outfile << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
			outfile << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
			outfile << "                    `:%;.  :;bd%;          %;@%;'\n";
			outfile << "                      `@%:.  :;%.         ;@@%;'\n";
			outfile << "                        `@%.  `;@%.      ;@@%;\n";     
			outfile << "                          `@%%. `@%%    ;@@%;\n";     
			outfile << "                            ;@%. :@%%  %@@%;\n";    
			outfile << "                              %@bd%%%bd%%:;\n"; 
			outfile << "                                #@%%%%%:;;\n";
			outfile << "                                %@@%%%::;\n";
			outfile << "                                %@@@%(o);  . '\n";         
			outfile << "                                %@@@o%;:(.,'\n";     
			outfile << "                            `.. %@@@o%::;\n";   
			outfile << "                               `)@@@o%::;\n";      
			outfile << "                                %@@(o)::;\n";  
			outfile << "                               .%@@@@%::;\n";    
			outfile << "                               ;%@@@@%::;.\n";
			outfile << "                              ;%@@@@%%:;;;.\n";
			outfile << "                          ...;%@@@@@%%:;;;;,..";
			outfile.close();
			std::cout << executor.getName() + " executed " + this->name << std::endl;
		}
		else
			std::cerr << executor.getName() + " not enough grade" << std::endl;
	}
	else
		std::cerr << this->name + " before being beSigned" << std::endl;
}

ShrubberyCreationForm	*ShrubberyCreationForm::clone(const std::string name) { return (new ShrubberyCreationForm(name, false, 145, 137)); }
