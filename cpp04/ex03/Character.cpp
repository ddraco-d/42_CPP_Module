/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:45:06 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 22:37:41 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name):
	name(name), equippedAmount(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::~Character()
{
	if (this->equippedAmount > 0)
		for (int i = 0; i < this->equippedAmount; i++)
			delete this->inventory[i];
}

std::string const &Character::getName(void) const
{
	return (this->name);
}

Character::Character(Character const &other):
	name(other.name), equippedAmount(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
	for (int i = 0; i < other.equippedAmount; i++)
		this->equip(other.inventory[i]->clone());
}

Character &Character::operator=(Character const &character)
{
	this->name = character.name;
	for (int i = 0; i < this->equippedAmount; i++)
		delete this->inventory[i];
	this->equippedAmount = 0;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
	for (int i = 0; i < character.equippedAmount; i++)
		this->equip(character.inventory[i]->clone());
	return (*this);
}

void Character::equip(AMateria *m)
{
	if (this->equippedAmount != 4 && m != nullptr)
	{
		for (int i = 0; i < this->equippedAmount; i++)
			if (this->inventory[i] == m)
				return ;
		this->inventory[this->equippedAmount] = m;
		this->equippedAmount += 1;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < this->equippedAmount && this->inventory[idx] != nullptr)
	{
		for (int i = idx; i < 3; i++)
		{
			this->inventory[i] = this->inventory[i + 1];
			this->inventory[i + 1] = nullptr;
		}
		this->equippedAmount -= 1;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < this->equippedAmount && this->inventory[idx] != nullptr)
		this->inventory[idx]->use(target);
}