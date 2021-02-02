/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:49:11 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 16:40:20 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name) : name(name)
{
	std::cout << "ClapTrap " << name << " constructor." << std::endl;
	this->level = 1;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->meleeAttackDamage = 100;
	this->rangedAttackDamage = 100;
	this->armorDamageReduction = 100;
}

ClapTrap::ClapTrap(ClapTrap const &other):
	name(other.name)
{
	std::cout << "ClapTrap " << name << " copy constructor." << std::endl;
	this->level = other.level;
	this->hitPoints = other.hitPoints;
	this->maxHitPoints = other.maxHitPoints;
	this->energyPoints = other.energyPoints;
	this->maxEnergyPoints = other.maxEnergyPoints;
	this->meleeAttackDamage = other.meleeAttackDamage;
	this->rangedAttackDamage = other.rangedAttackDamage;
	this->armorDamageReduction = other.armorDamageReduction;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	this->name = other.name;
	this->level = other.level;
	this->hitPoints = other.hitPoints;
	this->maxHitPoints = other.maxHitPoints;
	this->energyPoints = other.energyPoints;
	this->maxEnergyPoints = other.maxEnergyPoints;
	this->meleeAttackDamage = other.meleeAttackDamage;
	this->rangedAttackDamage = other.rangedAttackDamage;
	this->armorDamageReduction = other.armorDamageReduction;
	return (*this);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		std::cout << "no damage!" << std::endl;
	else if (hitPoints > 0)
	{
		if (armorDamageReduction >= amount)
			std::cout << "armor saved!" << std::endl;
		else
		{
			hitPoints -= (amount - armorDamageReduction);
			if (hitPoints < 0)
			{
				std::cout << "Dead\n";
				hitPoints = 0;
			}
			std::cout << name << " take damage " << amount << " ; HP = " << hitPoints << std::endl;
		}
	}
	else if (hitPoints == 0)
		std::cout << name << " cant damage, already dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "cant repair! hp = 0" << std::endl;
	else if (amount == 0)
		std::cout << "you should pass value amount higher than 0!" << std::endl;
	else if (hitPoints + amount <= maxHitPoints)
	{
		hitPoints += amount;
		std::cout << "repaired " << amount << " ; HP = " << hitPoints << std::endl;
	}
	else if (amount + hitPoints > maxHitPoints)
	{
		hitPoints = maxHitPoints;
		std::cout << "maximum repaired!" << " HP = " << hitPoints << std::endl;
	}
}

std::string ClapTrap::getName()
{
	return(this->name);
}