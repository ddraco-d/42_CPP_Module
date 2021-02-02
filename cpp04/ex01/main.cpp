/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:37:42 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:36:32 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"

int main()
{

	 PowerFist powerFist;
	 PlasmaRifle plasmaRifle;

	 powerFist.attack();
	 plasmaRifle.attack();

	 AWeapon& CheckAssign = powerFist;
	 CheckAssign.attack();
	 std::cout << std::endl << std::endl;


	 Character character("character");
	 Enemy* enemy = new SuperMutant();
	 std::cout << enemy->getType() << std::endl;
	 delete enemy;
	 std::cout << std::endl << std::endl;

	 character.equip(&plasmaRifle);
	 std::cout << character;
	 character.equip(nullptr);
	 std::cout << character;

    std::cout << "\n\n___Check_from_subject____\n\n";
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	delete me;
	delete pr;
	delete pf;
	return (0);
}