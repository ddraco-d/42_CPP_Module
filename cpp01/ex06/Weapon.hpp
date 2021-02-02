/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:50:50 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/19 01:02:05 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	const std::string &getType() const;
	void setType(const std::string &type);
	Weapon(const std::string &type);
	Weapon();
	~Weapon();
};

#endif