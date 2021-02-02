/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:55:01 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/19 00:45:08 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>
# include <sstream>

class Brain
{
private:
	int size;
public:
	std::string identify() const;
	Brain(int size);
	int getSize() const;
	Brain();
	~Brain();
};

#endif