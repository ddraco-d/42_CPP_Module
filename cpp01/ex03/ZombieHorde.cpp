/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:15:40 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/18 14:47:35 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : N(N)
{
	if (N > 0)
	{
		this->zombies = new Zombie[N];
		for (int i = 0; i < N; i++)
			zombies[i].setAll("Standart", Zombie::makeRandomName());
	}
	else
		std::cout << "N must be higher than zero\n";
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "Horde is being destroyed !" << std::endl;
	delete[] this->zombies;
}
void ZombieHorde::announce(void)
{
	for (int i = 0; i < this->N; i++)
		this->zombies[i].anounce();
}