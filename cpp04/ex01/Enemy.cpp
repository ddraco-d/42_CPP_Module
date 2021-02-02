/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:09:37 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 21:36:03 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, const std::string &type) : hp(hp), type(type)
{}

Enemy::~Enemy()
{}

const std::string &Enemy::getType() const
{
	return (this->type);
}

int Enemy::getHP() const
{
	return (this->hp);
}

void Enemy::takeDamage(int amount)
{
	if (amount > 0)
	{
		this->hp -= amount;
		if (this->hp < 0)
			this->hp = 0;
	}
}

Enemy::Enemy(Enemy const &other):
	hp(other.hp), type(other.type)
{
}



Enemy &Enemy::operator=(const Enemy &enemy)
{
	this->type = enemy.type;
	this->hp = enemy.hp;
	return (*this);
}
