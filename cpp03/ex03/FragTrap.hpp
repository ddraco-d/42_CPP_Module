/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:30:53 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 16:07:59 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	static std::string FunnyAttacks[5];
public:
	FragTrap();

	FragTrap(std::string name);
	FragTrap(FragTrap const &other);
	FragTrap &operator=(FragTrap const &other);
	virtual ~FragTrap();

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void vaulthunter_dot_exe(std::string const &target);
};

#endif
