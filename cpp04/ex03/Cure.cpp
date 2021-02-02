/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:45:02 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 23:21:54 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(Cure const &other): AMateria("cure")
{
	this->_xp = other._xp;
}

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{}

Cure &Cure::operator=(Cure const &cure)
{
	this->_xp = cure._xp;
	return (*this);
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}