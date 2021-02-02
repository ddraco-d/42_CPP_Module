/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:43:22 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:57:58 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria &AMateria::operator=(const AMateria &aMateria)
{
	this->_type = aMateria._type;
	this->_xp = aMateria._xp;
	return (*this);
}

AMateria::AMateria(std::string const &type):
	_type(type), _xp(0)
{
}

AMateria::AMateria(const AMateria &other)
{
	this->_type = other._type;
	this->_xp = other._xp;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int AMateria::getXP(void) const
{
	return (this->_xp);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	this->_xp += 10;
}