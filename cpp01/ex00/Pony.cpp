/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:46:36 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/17 14:51:21 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, int age) : name(name), age(age)
{
	std::cout << "Pony constructed with name: " << name << std::endl;
}

Pony::~Pony()
{
	std::cout << "Pony destructed with name: " << name << std::endl;
}

void Pony::tellSmth()
{
	std::cout << "Hi, my name is " << name << ", age is " << age << std::endl;
}