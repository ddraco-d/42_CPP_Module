/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:31:51 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 12:54:09 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "unistd.h"

int main()
{
	FragTrap frag("Vova");

	//damage
	frag.takeDamage(0);
	read(0,0,1);
	frag.takeDamage(5);
	read(0,0,1);
	frag.takeDamage(60);
	read(0,0,1);


	//repair

	frag.beRepaired(0);
	read(0,0,1);
	frag.beRepaired(55);
	read(0,0,1);
	frag.beRepaired(5000);
	read(0,0,1);

	//attack

	frag.rangedAttack("Target1");
	read(0,0,1);
	frag.meleeAttack("Target2");
	read(0,0,1);

	//random

	frag.vaulthunter_dot_exe("Target3");
	read(0,0,1);

	//death

	frag.takeDamage(3000);
	read(0,0,1);
	frag.meleeAttack("Test_isdead");
	frag.vaulthunter_dot_exe("Funny_attack_2_of_5");
	frag.beRepaired(100);

	return 0;
}