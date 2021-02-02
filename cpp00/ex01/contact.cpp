/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:15:21 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/16 19:19:23 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conctact.hpp"

std::string contact::fields[11] = {
	"first_name",
	"last_name",
	"nickname",
	"login",
	"postal_adress",
	"email_adress",
	"phone_number",
	"birthday_date",
	"favorite_meal",
	"underwear_color",
	"darkset_secret"
};

bool contact::add(void)
{
	int checkLength = 0;
	for (int i = 0; i < 11; i++)
	{
		std::cout << fields[i] << ": \n";
		std::getline(std::cin, information[i]);
		checkLength += information[i].length();
	}
	if (checkLength == 0)
	{
		std::cout << "Nothing added\n";
		return (0);
	}
	std::cout << "Done!\n";
	return (1);
}

void contact::look(void)
{
	for (int i = 0; i < 11; i++)
	{
		std::cout << fields[i] << ": ";
		std::cout << information[i] << std::endl;
	}
}

std::string* contact::get_info()
{
	return(information);
}

