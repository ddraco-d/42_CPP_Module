/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:47:31 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 14:02:32 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"

class Squad : public ISquad
{
private:
	int unitsAmount;
	ISpaceMarine **units;
public:
	~Squad();
	Squad();
	Squad(const Squad&);
	int getCount() const;
	Squad& operator=(const Squad&);
	ISpaceMarine *getUnit(int i) const;
	int push(ISpaceMarine *marine);
};


#endif
