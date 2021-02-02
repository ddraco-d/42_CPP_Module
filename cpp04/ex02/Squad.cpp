/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:47:40 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 13:37:28 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : unitsAmount(0), units(nullptr)
{}

Squad::Squad(const Squad &other) : unitsAmount(0), units(nullptr)
{
	this->unitsAmount = 0;
	for (int i = 0; i < other.getCount(); i++)
		this->push(other.getUnit(i)->clone());
}

Squad &Squad::operator=(const Squad &squad)
{
	if (this->units)
	{
		for (int i = 0; i < this->unitsAmount; i++)
			delete this->units[i];
		delete this->units;
		this->units = nullptr;
	}
	this->unitsAmount = 0;
	for (int i = 0; i < squad.getCount(); i++)
		this->push(squad.getUnit(i)->clone());
	return (*this);
}

Squad::~Squad()
{
	if (this->unitsAmount)
	{
		for (int i = 0; i < this->unitsAmount; ++i)
		{
			delete this->units[i];
		}
		delete this->units;
	}
}

int Squad::getCount() const
{
	return (this->unitsAmount);
}

ISpaceMarine *Squad::getUnit(int i) const
{
	if (i < this->unitsAmount && i >= 0)
		return (this->units[i]);
	return (nullptr);
}

int Squad::push(ISpaceMarine *unit)
{
	if (!unit)
		return (this->unitsAmount);
	if (this->units)
	{
		for (int i = 0; i < this->unitsAmount; i++)
			if (this->units[i] == unit)
				return (this->unitsAmount);
		ISpaceMarine **temp = new ISpaceMarine*[this->unitsAmount + 1];
		for (int i = 0; i < this->unitsAmount; i++)
			temp[i] = this->units[i];
		delete[] this->units;
		this->units = temp;
		this->units[this->unitsAmount] = unit;
		this->unitsAmount++;
	}
	else
	{
		this->units = new ISpaceMarine*[1];
		this->units[0] = unit;
		this->unitsAmount = 1;
	}
	return (this->unitsAmount);
}


