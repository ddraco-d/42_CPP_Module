/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:26:15 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:35:47 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	Character();
	std::string name;
	int ap;
	AWeapon *weapon;
public:
	Character(std::string const & name);
	Character(const Character& other);
	Character& operator=(const Character& character);
	~Character();
	const std::string& getName() const;
	int getAp() const;
	AWeapon *getAWeapon() const;
	void recoverAP(void);
	void equip(AWeapon* weapon);
	void attack(Enemy* enemy);

};

std::ostream &operator<<(std::ostream &out, const Character &character);

#endif
