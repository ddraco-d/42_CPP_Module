/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:10:08 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/22 17:26:17 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>
# include <ctime>

class Zombie
{
private:
	std::string type;
	std::string name;
public:
	void anounce();
	static std::string makeRandomName();
	Zombie(std::string type, std::string name);
	~Zombie();
	Zombie();
	void setAll(std::string type, std::string name);
};

#endif