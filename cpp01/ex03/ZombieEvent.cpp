/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:30:17 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/18 01:06:25 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(this->type, name));
}

Zombie* ZombieEvent::randomChump(void)
{
	Zombie *zombie;

	zombie = new Zombie(this->type, Zombie::makeRandomName());
	zombie->anounce();
	return (zombie);
}

ZombieEvent::ZombieEvent()
{
	srand(time (0));
}

ZombieEvent::~ZombieEvent()
{
}