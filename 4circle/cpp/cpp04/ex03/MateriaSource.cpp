/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:29:09 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/03 17:05:26 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->ice = NULL;
	this->cure = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &m)
{
	this->ice = NULL;
	this->cure = NULL;
	if (m.ice)
		this->ice = m.ice;
	if (m.cure)
		this->cure = m.cure;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &m)
{
	if (this != &m)
	{
		if (this->ice)
		{
			delete this->ice;
			this->ice = NULL;
		}
		if (this->cure)
		{
			delete this->cure;
			this->cure = NULL;
		}
		if (m.ice)
			this->ice = new Ice();
		if (m.cure)
			this->cure = new Cure();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	if (this->ice)
		delete ice;
	if (this->cure)
		delete cure;
}

void	MateriaSource::learnMateria(AMateria* type)
{
	if (type)
	{
		if (!type->getType().compare("ice"))
			this->ice = dynamic_cast<Ice*>(type);
		else if (!type->getType().compare("cure"))
			this->cure = dynamic_cast<Cure*>(type);
	}
	else
		std::cout << "before learning a skill!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (!type.empty())
	{
		if (!type.compare("ice") && this->ice)
			return (new Ice());
		if (!type.compare("cure") && this->cure)
			return (new Cure());
	}
	return (NULL);
}
