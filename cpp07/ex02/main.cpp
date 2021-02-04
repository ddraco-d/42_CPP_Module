/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:08:17 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/04 20:08:54 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> int_arr1;

	Array<int> int_arr2(5);
	int_arr1 = int_arr2;
	for (size_t i = 0; i < int_arr1.size(); i++)
	{
		int_arr1[i] = i;
		std::cout << int_arr1[i] << " ";
	}
	std::cout << std::endl;

	Array<float> float_arr1(5);
	for (size_t i = 0; i < float_arr1.size(); i++) {
		std::cout << float_arr1[i] << "f ";
	}
	std::cout << std::endl;

	Array<std::string> string_arr1(5);
	for (size_t i = 0; i < 5; i++)
		string_arr1[i] = "Hi42";
	for (size_t i = 0; i < string_arr1.size(); i++)
		std::cout << string_arr1[i] << std::endl;

	std::cout << "------------" << std::endl;

	try
	{
		int_arr2[-1] = 2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		int_arr2[5000] = 2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
