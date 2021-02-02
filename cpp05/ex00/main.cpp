/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:07:59 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/30 16:54:51 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("Ivan", 2);
		std::cout << test << std::endl;
		test.decGrade();
		std::cout << test << std::endl;
		test.incGrade();
		test.incGrade();
		std::cout << test << std::endl;
		test.incGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------\n";
	try
	{
		Bureaucrat test1("Ivan", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------\n";
	try
	{
		Bureaucrat test2("Ivan", 149);
		std::cout << test2 << std::endl;
		test2.decGrade();
		std::cout << test2 << std::endl;
		test2.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return (0);
}
