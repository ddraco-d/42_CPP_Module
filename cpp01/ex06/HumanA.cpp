/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:57:47 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/19 01:01:53 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon) :\
				name(name), weapon(weapon)
{
	
}

void HumanA::attack()
{
	std::cout << name + " attacks with his " + weapon.getType() << std::endl;
}