/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:43:37 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 23:16:45 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice(Ice const &other);
	virtual ~Ice();
	Ice &operator=(Ice const &other);
	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif