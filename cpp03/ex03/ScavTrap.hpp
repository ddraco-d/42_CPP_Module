/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:59:27 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 16:10:05 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	static std::string FunnyChallenges[5];
public:
	ScavTrap();

	ScavTrap(std::string name);
	ScavTrap &operator=(ScavTrap const &other);
	ScavTrap(ScavTrap const &other);
	virtual ~ScavTrap();
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);

	void challengeNewcomer();

};

#endif
