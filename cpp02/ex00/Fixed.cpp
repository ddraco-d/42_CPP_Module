/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:30:42 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/24 16:47:39 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor" << std::endl;
	this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor" << std::endl;
	this->value = other.getRawBits();
}


Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator" << std::endl;
	this->value = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
