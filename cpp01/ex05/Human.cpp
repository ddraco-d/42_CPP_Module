/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:55:03 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/19 00:43:01 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

std::string Human::identify(void) const
{
	return (this->humanBrain.identify());
}

const Brain &Human::getBrain(void) const
{
	return (this->humanBrain);
}

Human::Human()
{

}

Human::~Human()
{
}
