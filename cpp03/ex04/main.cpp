/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:31:51 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 17:58:13 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include "unistd.h"

int main()
{
	ClapTrap clap("CL");
	FragTrap frag("Vova");
	ScavTrap scav("Petya");
	NinjaTrap ninja("Ninja");
	NinjaTrap ninjaTrap("TrappedNinja");
	SuperTrap super("Super");

	//damage
	frag.takeDamage(0);
	scav.takeDamage(0);
	ninja.takeDamage(0);
	super.takeDamage(0);
	// read(0,0,1);
	frag.takeDamage(5);
	scav.takeDamage(5);
	ninja.takeDamage(5);
	super.takeDamage(5);
	// read(0,0,1);
	frag.takeDamage(50);
	scav.takeDamage(50);
	ninja.takeDamage(50);
	super.takeDamage(50);
	read(0,0,1);


	//repair

	frag.beRepaired(0);
	scav.beRepaired(0);
	ninja.beRepaired(0);
	super.beRepaired(0);
	read(0,0,1);
	frag.beRepaired(55);
	scav.beRepaired(55);
	ninja.beRepaired(55);
	super.beRepaired(55);
	read(0,0,1);
	frag.beRepaired(5000);
	scav.beRepaired(5000);
	ninja.beRepaired(5000);
	super.beRepaired(5000);
	read(0,0,1);

	//attack

	frag.rangedAttack("Target1");
	scav.rangedAttack("Target1");
	ninja.rangedAttack("Target3");
	super.rangedAttack("Target4");
	read(0,0,1);
	frag.meleeAttack("Target2");
	scav.meleeAttack("Target2");
	ninja.meleeAttack("Target3");
	super.meleeAttack("Target4");
	read(0,0,1);
	//random

	frag.vaulthunter_dot_exe("Target1");
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
	
	//super
	
	super.vaulthunter_dot_exe("Target1");
	read(0,0,1);
	super.ninjaShoebox(ninjaTrap);

	//death

	frag.takeDamage(3000);
	scav.takeDamage(5000);
	ninja.takeDamage(5000);
	super.takeDamage(5000);
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
	//super
	super.beRepaired(100);
	return 0;
}