/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:06:50 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:37:42 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist()
	: AWeapon("Power Fist", 8, 50)
{}

PowerFist::PowerFist(const PowerFist &other)
	: AWeapon(other)
{}

PowerFist::~PowerFist()
{}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist &PowerFist::operator=(const PowerFist &powerFist)
{
	this->name = powerFist.name;
	this->apCost = powerFist.apCost;
	this->damage = powerFist.damage;
	return (*this);
}
