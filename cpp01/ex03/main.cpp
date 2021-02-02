/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:15:50 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/18 14:48:46 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main(void)
{
	std::cout << "Creating two hordes with 10 zombies\n";
	ZombieHorde first(10);
	ZombieHorde second(10);
	
	std::cout << "First horde\n";
	first.announce();
	std::cout << "Second horde\n";
	second.announce();
	return (0);
}