/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:07:59 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/30 18:12:13 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat test("Ivan", 50);
	Form form("Test_form", 51, 100);
	form.beSigned(test);
	std::cout << form;
	std::cout << "\n-----------\n";
	Form form1("Test_form_1", 49, 100);
	try
	{
		test.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << form1;
	std::cout << "\n-----------\n";
	try
	{
		Form form("Test_form", 151, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------\n";
	return (0);
}
