/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 23:31:55 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:35:07 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
protected:
	AWeapon();
	std::string name;
	int apCost;
	int damage;
public:
	AWeapon(const std::string &name, int apCost, int damage);
	AWeapon(const AWeapon& other);
	AWeapon& operator=(const AWeapon& aWeapon);
	virtual ~AWeapon();
	const std::string& getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};


#endif
