/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:22:31 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/18 01:02:33 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string type;
public:
	void setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	Zombie* randomChump(void);
	ZombieEvent();
	~ZombieEvent();
};

#endif