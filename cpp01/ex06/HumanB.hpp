/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:57:52 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/19 01:09:35 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    const Weapon *weapon;
public:
    HumanB();
    HumanB(const std::string &name);
    ~HumanB();
    void setWeapon(const Weapon &weapon);
    void attack(void);
};

#endif