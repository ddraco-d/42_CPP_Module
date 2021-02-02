/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:30:39 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 17:32:21 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap worked\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Constructor FragTrap worked\n";
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
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
		std::cout << "Dead(ClapTrap)." << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	if (hitPoints > 0)
	{
		std::cout << "FR4G-TP " << name << " attacks <" << target << "> at range, causing <" \
				<< meleeAttackDamage << "> points of damage!" << std::endl;
	}
	else
		std::cout << "Dead(ClapTrap).\n" << std::endl;
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

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other.name)
{
	std::cout << "Copy constructor(FragTrap)\n" << std::endl;
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