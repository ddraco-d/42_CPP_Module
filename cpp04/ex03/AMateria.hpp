/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:43:23 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/27 23:02:14 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
private:
	AMateria();
protected:
	std::string _type;
	unsigned int _xp;
public:
	AMateria(std::string const &type);
	AMateria(const AMateria&);
	AMateria& operator=(const AMateria&);
	virtual ~AMateria();

	std::string const &getType(void) const;
	unsigned int getXP(void) const;

	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &target);
};

#endif