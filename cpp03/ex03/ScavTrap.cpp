/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:59:31 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 17:33:21 by ddraco           ###   ########.fr       */
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

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor worked\n";
	srand(time(NULL));
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
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

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other.name)
{
	std::cout << "Copy constructor(ScavTrap)\n" << std::endl;
	this->name = other.name;
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