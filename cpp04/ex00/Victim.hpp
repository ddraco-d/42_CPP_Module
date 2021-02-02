/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:38:01 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/26 22:52:42 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
protected:
	Victim();
	std::string name;
public:
	Victim(std::string const &name);
	Victim(const Victim& other);
	virtual ~Victim();

	Victim &operator=(const Victim& other);

	std::string const &getName(void) const;
	virtual void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &out, Victim const &victim);

#endif