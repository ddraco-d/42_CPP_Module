/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:26:26 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 17:35:48 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "Ninja trap constructor\n" << std::endl;
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
}

NinjaTrap::NinjaTrap(NinjaTrap const &other): ClapTrap(other.name)
{
	std::cout << "Copy contructor NinjaTrap" << std::endl;
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

NinjaTrap::~NinjaTrap()
{
	std::cout << "Ninja trap destructor"  << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &other)
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

void NinjaTrap::meleeAttack(std::string const &target)
{
	if (hitPoints > 0)
	{
		std::cout << this->name << " throw Katana and deals "
				<< this->meleeAttackDamage << " points of damage to "
				<< target << std::endl;
	}
	else
		std::cout << "Dead(NinjaTrap).\n" << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target)
{
	if (hitPoints > 0)
	{
		std::cout << this->name << " throw a Shuriken at "
				<< target << " and deals " << this->meleeAttackDamage
				<< " points of damage!" << std::endl;
	}
	else
		std::cout << "Dead(NinjaTrap).\n" << std::endl; 
}

void NinjaTrap::ninjaShoebox(FragTrap &trap)
{
	if (this->hitPoints == 0)
	{
		std::cout << "already dead, cant do shoebox" << std::endl;
		return ;
	}
	std::cout << this->name << " tries to kill " << trap.getName()
			<< " but failed" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
	if (this->hitPoints == 0)
	{
		std::cout << "already dead, cant do shoebox" << std::endl;
		return ;
	}
	if (this->energyPoints >= 20)
	{
		this->energyPoints -= 20;
		std::cout << this->name << " damaged " << trap.getName()
				<< " for " << this->rangedAttackDamage << std::endl;
		trap.takeDamage(this->rangedAttackDamage);
	}
	else
		std::cout << this->name << " has not enough energy." << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
	if (this->hitPoints == 0)
	{
		std::cout << "already dead, cant do shoebox" << std::endl;
		return ;
	}
	if (this->energyPoints >= 60)
	{
		this->energyPoints -= 60;
		std::cout << this->name << " killed the ClapTrap " << trap.getName()
				<< " FINALLY!" << std::endl;
		trap.takeDamage(5000);
	}
	else
	{
		std::cout << this->name << " saw the ClapTrap " << trap.getName()
				<< " but smth went wrong and i'm fall." << std::endl;
		this->takeDamage(this->hitPoints + this->armorDamageReduction);
	}
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
	if (this->hitPoints == 0)
	{
		std::cout << "already dead, cant do shoebox" << std::endl;
		return ;
	}
	if ((rand() % 100) > 50)
	{
		std::cout << this->name << " throw Knife at " << trap.getName()
				<< " and damaged him for " << this->rangedAttackDamage << "!" << std::endl;
		trap.takeDamage(this->rangedAttackDamage);
	}
	else
	{
		std::cout << this->name << " throw Shuriken at " << trap.getName()
				<< " but misses" << std::endl;
	}
}