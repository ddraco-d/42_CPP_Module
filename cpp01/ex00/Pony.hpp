/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:46:38 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/22 17:25:26 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>
# include <string>

class Pony
{
private:
	std::string name;	
	int age;
public:
	void tellSmth();
	Pony(std::string name, int age);
	~Pony();
};

#endif