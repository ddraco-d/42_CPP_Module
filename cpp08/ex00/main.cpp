/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:26:44 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/05 16:09:54 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>

void	vector_check(void) {
	std::vector<int> check;
	int tofind = 5;
	std::cout << "int tofind is " << tofind << std::endl;
	for (int i = 0; i < 10; i++)
		check.push_back(rand() % 100);
	std::cout << "Содержимое ветора\n";
	for (int i = 0; i < 10; i++)
		std::cout << check[i] << "\t";
	std::cout << std::endl;
	try {
		std::vector<int>::iterator found = easyfind(check, tofind);
		std::cout << "Element found: " << *found << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	list_check(void) {
	std::list<int> check;
	int tofind = 5;
	std::cout << "int tofind is " << tofind << std::endl;
	for (int i = 0; i < 10; i++)
		check.push_back(rand() % 50);
	std::cout << "Содержимое листа\n";
	for (std::list <int>::iterator k = check.begin(); k != check.end(); ++k)
		std::cout << *k << "\t";
	std::cout << std::endl;
	try {
		std::list <int>::iterator found = easyfind(check, tofind);
		std::cout << "Element found: " << *found << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void) {
	srand(time(NULL));
	vector_check();
	list_check();
}