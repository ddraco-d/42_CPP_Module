/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:48:38 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 23:03:09 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
private:
	Peon();
public:
	Peon(std::string const &name);
	Peon(Peon const &peon);
	virtual ~Peon();

	Peon &operator=(const Peon& other);

	void getPolymorphed(void) const;
};

#endif