/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:54:57 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/19 00:45:30 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : size(10)
{
}

Brain::Brain(int size) : size(size)
{
}

Brain::~Brain()
{
}

int Brain::getSize(void) const
{
	return (this->size);
}

std::string Brain::identify() const
{
	std::stringstream ss;
	ss << "0x" << std::uppercase << std::hex << (long)this;
	return (ss.str());
}