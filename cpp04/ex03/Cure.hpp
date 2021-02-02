/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:45:00 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 22:06:15 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure();
	Cure(Cure const &other);
	virtual ~Cure();

	Cure &operator=(Cure const &other);

	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif