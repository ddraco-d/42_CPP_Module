/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:30:42 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/24 22:53:35 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (value << Fixed::bit);
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << Fixed::bit));
}


Fixed::~Fixed()
{
	std::cout << "Destructor" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor" << std::endl;
	*this = other;
}


Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator" << std::endl;
	this->value = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << Fixed::bit));
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bit);
}

std::ostream &operator<<(std::ostream &o, Fixed const &value)
{
    o << value.toFloat();
    return (o);
}