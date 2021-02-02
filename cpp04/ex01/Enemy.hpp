/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:09:32 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:36:16 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

# include <iostream>

class Enemy {
protected:
	int hp;
	std::string type;
	Enemy();
public:
	Enemy(int hp, std::string const & type);
	Enemy(const Enemy& other);
	Enemy& operator=(const Enemy& enemy);
	virtual ~Enemy();
	const std::string& getType() const;
	int getHP() const;
	virtual void takeDamage(int);

};

#endif
