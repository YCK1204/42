/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:18:05 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/12 12:48:35 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string name, const bool Sign, const int ToSign, const int ToExecute);
	ShrubberyCreationForm(const ShrubberyCreationForm &s);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &s);
	~ShrubberyCreationForm();
	void	execute(Bureaucrat const & executor) const;
	ShrubberyCreationForm	*clone(const std::string name);
};

#endif
