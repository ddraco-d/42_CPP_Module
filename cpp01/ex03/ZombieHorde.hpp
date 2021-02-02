/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:12:41 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/18 14:35:51 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include "Zombie.hpp"
# include "ZombieEvent.hpp"

class ZombieHorde
{
private:
	int			N;
	Zombie		*zombies;
public:
	ZombieHorde(int N);
	~ZombieHorde();
	void announce(void);
};

#endif