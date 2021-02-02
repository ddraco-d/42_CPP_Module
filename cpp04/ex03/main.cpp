/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:53:07 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/28 00:06:41 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main(void)
{
	std::cout << "\n\n___START SUBJECT-MAIN TEST___\n\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << "\n\n____END SUBJECT-MAIN TEST___\n\n";

	Character character("check");
	AMateria *materia = new Cure;
	AMateria *materia1 = new Ice;
	character.equip(materia);
	character.equip(materia1);
	character.use(2, character);
	character.use(0, character);
	character.use(1, character);

	Character character1("check1");
	std::cout << "CPY CONSTRUCTOR & ASSIGNMENT" << std::endl;
	character1 = character;
	Character character2(character1);
	std::cout << character.getName() << std::endl;
	std::cout << character1.getName() << std::endl;
	std::cout << character2.getName() << std::endl;
	character.use(0, character);
	character.use(1, character);
	character.use(2, character);
	character1.use(0, character);
	character1.use(1, character);
	character1.use(2, character);
	character2.use(0, character);
	character2.use(1, character);
	character2.use(2, character);

	MateriaSource materiaSource;
	materiaSource.learnMateria(new Ice());
	materiaSource.learnMateria(new Cure());

	AMateria *materia2 = materiaSource.createMateria("ice");
	std::cout << materia2->getType() << std::endl;

	MateriaSource materiaSource1(materiaSource);
	MateriaSource materiaSource2;
	materiaSource2 = materiaSource1;
	delete materia2;	
	return (0);
}
