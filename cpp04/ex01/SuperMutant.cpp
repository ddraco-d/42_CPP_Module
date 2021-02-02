/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:18:53 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:38:28 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
	: Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &other)
	: Enemy(other)
{}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int amount)
{
	Enemy::takeDamage(amount - 3);
}

SuperMutant &SuperMutant::operator=(const SuperMutant &superMutant)
{
	this->type = superMutant.type;
	this->hp = superMutant.hp;
	return (*this);
}
