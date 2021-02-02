/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:30:39 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 13:02:27 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
	std::cout << "Destructor worked\n";
}

FragTrap::FragTrap(std::string name) : name(name)
{
	std::cout << "Constructor worked\n";
	level = 1;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
}

std::string FragTrap::FunnyAttacks[5] = {
	"Back in my day..",
	"Get off my lawn!",
	"Coffee? Black... like my soul.",
	"At least I still have my teeth!",
	"Take two bullets, then call me in the morning."
};

void FragTrap::rangedAttack(std::string const &target)
{
	if (hitPoints > 0)
	{
		std::cout << "FR4G-TP " << name << " attacks <" << target << "> at range, causing <"\
			 << rangedAttackDamage << "> points of damage!" << std::endl;
	}
	else
		std::cout << "Dead." << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	if (hitPoints > 0)
	{
		std::cout << "FR4G-TP " << name << " attacks <" << target << "> at range, causing <" \
				<< meleeAttackDamage << "> points of damage!" << std::endl;
	}
	else
		std::cout << "Dead.\n" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		std::cout << "no damage!" << std::endl;
	else if (hitPoints > 0)
	{
		if (armorDamageReduction >= amount)
			std::cout << "armor saved!" << std::endl;
		else
		{
			hitPoints -= (amount + armorDamageReduction);
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

void FragTrap::beRepaired(unsigned int amount)
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

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (hitPoints == 0 || energyPoints == 0)
		std::cout << "hp == 0 or energy points == 0" << std::endl;
	else if (energyPoints >= 25)
	{
		srand(time(NULL));
		energyPoints -= 25;
		int random = rand() % 5;
		std::cout << this->name << ": "<< FragTrap::FunnyAttacks[random] << std::endl\
			<< this->name << " attacks "
				<< target << " for " << ((rand() % this->meleeAttackDamage) + 1)
					<< " points of damage!" << std::endl;
	}
	else
		std::cout << "not enougth energy points to do this!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
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

FragTrap::FragTrap(FragTrap const &other) : name(other.name)
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