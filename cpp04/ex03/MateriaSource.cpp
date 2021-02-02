/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:44:53 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/28 00:05:14 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : sourceAmount(0)
{
	for (int i = 0; i < 4; i++)
		this->sources[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->sourceAmount; i++)
		delete this->sources[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->sourceAmount != 4 && m != nullptr)
		this->sources[this->sourceAmount++] = m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->sourceAmount; i++)
		if (this->sources[i]->getType() == type)
			return (this->sources[i]->clone());
	return (0);
}

MateriaSource::MateriaSource(MateriaSource const &other):
	sourceAmount(0)
{
	for (int i = 0; i < 4; i++)
		this->sources[i] = nullptr;
	for (int i = 0; i < other.sourceAmount; i++)
		this->learnMateria(other.sources[i]->clone());
}


MateriaSource &MateriaSource::operator=(MateriaSource const &materiaSource)
{
	for (int i = 0; i < this->sourceAmount; i++)
		delete this->sources[i];
	this->sourceAmount = 0;
	for (int i = 0; i < 4; i++)
		this->sources[i] = nullptr;
	for (int i = 0; i < materiaSource.sourceAmount; i++)
		this->learnMateria(materiaSource.sources[i]->clone());
	return (*this);
}