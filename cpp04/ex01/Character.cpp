/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:26:22 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:35:28 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name)
: name(name), ap(40), weapon(nullptr)
{}

Character::Character(Character const &other):
	name(other.name), ap(other.ap), weapon(other.weapon)
{}

Character::~Character() 
{}

Character &Character::operator=(const Character &character)
{
	this->name = character.name;
	this->ap = character.ap;
	this->weapon = character.weapon;
	return (*this);
}

const std::string &Character::getName() const
{
	return (this->name);
}

int Character::getAp() const
{
	return (this->ap);
}

AWeapon *Character::getAWeapon() const
{
	return (this->weapon);
}

void Character::recoverAP()
{
	this->ap += 10;
	this->ap = (this->ap > 40) ? 40 : this->ap;
}

void Character::equip(AWeapon *aWeapon)
{
	this->weapon = aWeapon;
}

void Character::attack(Enemy *enemy)
{
	if (this->weapon && this->weapon->getAPCost() <= this->ap)
	{
		std::cout << this->name << " attacks " << enemy->getType()
		<< " with a " << this->weapon->getName() << std::endl;
		this->ap -= this->weapon->getAPCost();
		this->weapon->attack();
		enemy->takeDamage(this->weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

std::ostream &operator<<(std::ostream &out, const Character &character)
{
	if (character.getAWeapon())
	{
		out << character.getName() << " has " << character.getAp()
		<< " AP and wields a " << character.getAWeapon()->getName() << std::endl;
	}
	else
	{
		out << character.getName() << " has "
		<< character.getAp() << " AP and is unarmed" << std::endl;

	}
	return (out);
}
