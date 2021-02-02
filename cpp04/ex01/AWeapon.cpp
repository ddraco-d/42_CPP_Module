/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:32:58 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:34:51 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apCost, int damage)
	: name(name), apCost(apCost), damage(damage)
{}

AWeapon::~AWeapon()
{}

const std::string& AWeapon::getName() const
{
	return (this->name);
}

int AWeapon::getAPCost() const
{
	return (this->apCost);
}

int AWeapon::getDamage() const
{
	return (this->damage);
}

AWeapon &AWeapon::operator=(const AWeapon &aWeapon)
{
	this->name = aWeapon.name;
	this->apCost = aWeapon.apCost;
	this->damage = aWeapon.damage;
	return (*this);
}

AWeapon::AWeapon(AWeapon const &other):
	name(other.name), apCost(other.apCost), damage(other.damage)
{}
