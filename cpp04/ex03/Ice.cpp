/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:44:59 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 23:19:19 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(Ice const &other) : AMateria("ice")
{
	this->_xp = other._xp;
}

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
	
}

Ice &Ice::operator=(Ice const &ice)
{
	this->_xp = ice._xp;
	return (*this);
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}