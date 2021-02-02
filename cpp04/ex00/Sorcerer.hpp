/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:28:43 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 22:47:43 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include "Victim.hpp"

class Sorcerer
{
private:
	Sorcerer();
	std::string name;
	std::string title;
public:
	Sorcerer(std::string const &name, std::string const &title);
	Sorcerer(const Sorcerer& other);
	virtual ~Sorcerer();
	Sorcerer &operator=(const Sorcerer& other);
	std::string const &getName(void) const;
	std::string const &getTitle(void) const;
	void polymorph(Victim const &victim) const;
};

std::ostream &operator<<(std::ostream &out, Sorcerer const &sorcerer);

#endif