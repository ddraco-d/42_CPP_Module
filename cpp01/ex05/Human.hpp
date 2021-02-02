/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:55:05 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/19 00:47:39 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CPP
# define HUMAN_CPP
# include "Brain.hpp"

class Human
{
private:
	const Brain humanBrain;
public:
	Human();
	~Human();
	const Brain &getBrain(void) const;
	std::string identify(void) const;
};


#endif