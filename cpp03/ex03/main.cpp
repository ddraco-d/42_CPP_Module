/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:31:51 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 16:58:45 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "unistd.h"

int main()
{
	ClapTrap clap("CL");
	FragTrap frag("Vova");
	ScavTrap scav("Petya");
	NinjaTrap ninja("Ninja");
	NinjaTrap ninjaTrap("TrappedNinja");


	//damage
	frag.takeDamage(0);
	scav.takeDamage(0);
	ninja.takeDamage(0);
	read(0,0,1);
	frag.takeDamage(5);
	scav.takeDamage(5);
	ninja.takeDamage(5);
	read(0,0,1);
	frag.takeDamage(50);
	scav.takeDamage(50);
	ninja.takeDamage(50);
	read(0,0,1);


	//repair

	frag.beRepaired(0);
	scav.beRepaired(0);
	ninja.beRepaired(0);
	read(0,0,1);
	frag.beRepaired(55);
	scav.beRepaired(55);
	ninja.beRepaired(55);
	read(0,0,1);
	frag.beRepaired(5000);
	scav.beRepaired(5000);
	ninja.beRepaired(5000);
	read(0,0,1);

	//attack

	frag.rangedAttack("Target1");
	scav.rangedAttack("Target1");
	ninja.rangedAttack("Target1");
	read(0,0,1);
	frag.meleeAttack("Target2");
	scav.meleeAttack("Target2");
	ninja.rangedAttack("Target2");
	read(0,0,1);

	//random

	frag.vaulthunter_dot_exe("Target3");
	scav.challengeNewcomer();
	read(0,0,1);
	ninja.ninjaShoebox(frag);
	read(0,0,1);
	ninja.ninjaShoebox(scav);
	read(0,0,1);
	ninja.ninjaShoebox(ninjaTrap);
	read(0,0,1);
	ninja.ninjaShoebox(clap);
	read(0,0,1);

	//death

	frag.takeDamage(3000);
	scav.takeDamage(5000);
	ninja.takeDamage(5000);
	read(0,0,1);
	//fragtrap
	frag.meleeAttack("Test_isdead");
	read(0,0,1);
	frag.vaulthunter_dot_exe("Funny_attack_2_of_5");
	read(0,0,1);
	frag.beRepaired(100);
	read(0,0,1);
	//scavtrap
	scav.meleeAttack("Test_isdead");
	read(0,0,1);
	scav.challengeNewcomer();
	read(0,0,1);
	scav.beRepaired(100);
	//ninja
	ninja.meleeAttack("Test_isdead");
	read(0,0,1);
	ninja.ninjaShoebox(frag);
	read(0,0,1);
	ninja.beRepaired(100);
	return 0;
}