/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:59:31 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 13:46:59 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string ScavTrap::FunnyChallenges[5] = {
	"Shit, challenges, Back in my day..",
	"Shit, challenges, Get off my lawn!",
	"Shit, challenges, Coffee? Black... like my soul.",
	"Shit, challenges, At least I still have my teeth!",
	"Shit, challenges, Take two bullets, then call me in the morning."
};

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor worked\n";
}

ScavTrap::ScavTrap(std::string name) : name(name)
{
	std::cout << "ScavTrap Constructor worked\n";
	srand(time(NULL));
	level = 1;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	armorDamageReduction = 3;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	if (hitPoints > 0)
	{
		std::cout << "FR4G-TP(ScavTrap) " << name << " attacks <" << target << "> at range, causing <"\
			 << rangedAttackDamage << "> points of damage!" << std::endl;
	}
	else
		std::cout << "Dead(ScavTrap)." << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	if (hitPoints > 0)
	{
		std::cout << "FR4G-TP(ScavTrap) " << name << " attacks <" << target << "> at range, causing <" \
				<< meleeAttackDamage << "> points of damage!" << std::endl;
	}
	else
		std::cout << "Dead(ScavTrap).\n" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
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

void ScavTrap::beRepaired(unsigned int amount)
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

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
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

ScavTrap::ScavTrap(ScavTrap const &other) : name(other.name)
{
	std::cout << "Copy constructor\n" << std::endl;
	this->level = other.level;
	this->hitPoints = other.hitPoints;
	this->maxHitPoints = other.maxHitPoints;
	this->energyPoints = other.energyPoints;
	this->maxEnergyPoints = other.maxEnergyPoints;
	this->meleeAttackDamage = other.meleeAttackDamage;
	this->rangedAttackDamage = other.rangedAttackDamage;
	this->armorDamageReduction = other.armorDamageReduction;
}

void ScavTrap::challengeNewcomer(void)
{
	if (hitPoints == 0)
		std::cout << "hp == 0" << std::endl;
	else
	{
		int random = rand() % 5;
		std::cout << this->name << ": "<< ScavTrap::FunnyChallenges[random] << std::endl;
	}
}