/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:59:27 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 13:37:46 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "FragTrap.hpp"

class ScavTrap
{
private:
	std::string name;
	int hitPoints;
	unsigned int maxHitPoints;
	int energyPoints;
	unsigned int maxEnergyPoints;
	unsigned int level;
	unsigned int meleeAttackDamage;
	unsigned int rangedAttackDamage;
	unsigned int armorDamageReduction;
	static std::string FunnyChallenges[5];
public:
	ScavTrap();

	ScavTrap(std::string name);
	ScavTrap &operator=(ScavTrap const &other);
	ScavTrap(ScavTrap const &other);
	~ScavTrap();

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void challengeNewcomer();

};

#endif
