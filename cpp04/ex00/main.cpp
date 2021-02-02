/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:52:18 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 23:08:22 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"

int main(void) 
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);


	std::cout << std::endl << std::endl;
	Peon hi("hello");
	Peon bye(hi);
	std::cout << hi << bye;
	std::cout << std::endl << std::endl;

	Sorcerer bocal("bocal", "The Greatest");
	Sorcerer adm("adm", "The most Powerful");
	Sorcerer adm_be_like("adm_be_like", "A little lesset than The most Powerful");
	std::cout << bocal << adm;
	adm_be_like = adm;
	std::cout << adm_be_like << bocal;
	std::cout << std::endl << std::endl;

	bocal.polymorph(joe);
	return (0);
}