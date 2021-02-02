/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:33:11 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/16 21:28:01 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conctact.hpp"

void all_contacts_table(int *counter, contact phoneBook[])
{
	std::cout << "|" << std::setw(10) << "INDEX" << "|"\
		<< "FIRST NAME"<< "|" << std::setw(10) << "LAST NAME" << "|" <<\
			std::setw(10) << "NICKNAME" << "|\n";
	for (int amount = 0; amount < *counter; amount++)
	{
		std::cout << "|" << std::setw(10) << amount;
		for (int i = 0; i < 3; i++)
		{
			std::cout << "|";
			if (phoneBook[amount].get_info()[i].length() > 10)
				std::cout << phoneBook[amount].get_info()[i].substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << phoneBook[amount].get_info()[i];
		}
		std::cout << "|" << std::endl;
	}
}

void search_contact(int *counter, contact phoneBook[])
{
	int index;
	all_contacts_table(counter, phoneBook);
	if (*counter == 0)
		std::cout << "No contacts\n";
	else if (*counter != 0)
	{
		while (1)
		{
			std::cout << "Enter Index\n";
			std::cin >> index;
			if (std::cin.fail() || !(index >= 0 && index < *counter))
			{
				std::cout << "Index incorrect\n";
				std::cin.clear(); 
				std::cin.ignore(32767, '\n'); 
				continue;
			}
			std::cout << "Contact [" << index << "]" << std::endl;
			phoneBook[index].look();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

void add_contact(int *counter, contact phoneBook[])
{
	if (*counter < 8)
	{
		if (phoneBook[*counter].add())
			*counter += 1;
	}
	else
		std::cout << "PhoneBook is full\n";
}

int main(void)
{
	std::string command;
	contact phoneBook[8];
	int	counter = 0;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT):" << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
		{
			std::cout << "Bye-Bye" << std::endl;
			break;
		}
		else if (command == "ADD")
			add_contact(&counter, phoneBook);
		else if (command == "SEARCH")
			search_contact(&counter, phoneBook);
	}
	return (0);
}