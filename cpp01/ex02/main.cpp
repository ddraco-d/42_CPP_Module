/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:15:50 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/18 14:02:30 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void workWithStack()
{
	Zombie thirdZombies[5];
	Zombie fourthZombies[5];

	std::cout << "Creating " << 5 << " third and fourth Zombie" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		thirdZombies[i].setAll("third", Zombie::makeRandomName());
		fourthZombies[i].setAll("fourth", Zombie::makeRandomName());
	}
	for (int i = 0; i < 5; i++)
	{
		thirdZombies[i].anounce();
		fourthZombies[i].anounce();
	}
}

void workWithHeap()
{
	ZombieEvent first;
	ZombieEvent second;
	Zombie *firstZombies[5];
	Zombie *secondZombies[5];

	first.setZombieType("first");
	std::cout << "Creating " << 5 << " first Zombie" << std::endl;
	for (int i = 0; i < 5; i++)
		firstZombies[i] = first.randomChump();
	second.setZombieType("second");
	std::cout << "Creating " << 5 << " second Zombie" << std::endl;
	for (int i = 0; i < 5; i++)
		secondZombies[i] = second.randomChump();
	std::cout << "Clean All first Zombies" << std::endl;
	for (int i = 0; i < 5; i++)
		delete firstZombies[i];
	std::cout << "Clean All second Zombies" << std::endl;
	for (int i = 0; i < 5; i++)
		delete secondZombies[i];
}

int main(void)
{
	workWithHeap();
	workWithStack();
	return (0);
}