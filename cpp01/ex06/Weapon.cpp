/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:52:30 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/19 01:02:34 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type)
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon() : type("Standart")
{
}

const std::string &Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}