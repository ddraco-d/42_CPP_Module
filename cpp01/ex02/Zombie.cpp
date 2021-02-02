/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:22:08 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/18 14:31:10 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::anounce()
{
	std::cout << "<" << this->name << "> (" << this->type << ") Braiiiiiiinnnssss...\n"; 
}

Zombie::Zombie(std::string type, std::string name) : type(type), name(name)
{	
}

void Zombie::setAll(std::string type, std::string name)
{
	this->name = name;
	this->type = type;	
}

Zombie::Zombie() : type("Default")
{}

Zombie::~Zombie()
{
	std::cout << "<" << this->name << "> (" << this->type << ") Died\n";
}

std::string Zombie::makeRandomName()
{
	std::string s;
	s = "Zombie ";
	s += std::to_string(1 + rand() % 50);
	return (s);
}