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

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat admin("admin", 1);
	std::cout << admin << std::endl;
	Bureaucrat check("check", 25);
	std::cout << check << std::endl;
	Bureaucrat low_check("low_check", 125);
	std::cout << check << std::endl;

	ShrubberyCreationForm shrub("Testtt");
	PresidentialPardonForm presid("presid");
	std::cout << shrub << std::endl;
	shrub.beSigned(admin);
	shrub.execute(check);
	std::cout << "\n---" << std::endl;

	try {
		presid.beSigned(admin);
		check.executeForm(presid);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try {
		RobotomyRequestForm robot("robo");
		std::cout << robot << std::endl;
		robot.execute(admin);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try {
		PresidentialPardonForm pres("pres");
		std::cout << pres << std::endl;
		admin.signForm(pres);
		pres.execute(check);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	return (0);
}
