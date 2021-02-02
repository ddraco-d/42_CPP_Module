/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:09:06 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/02 20:24:34 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Form *Intern::make_form(const std::string &formName, const std::string &target) {
	std::string suitable_words[3] = {"presidential", "shrubbery", "robotomy"};
	int ch = check(suitable_words, formName);
	Form *form = NULL;
	switch (ch) {
		case 0:
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		case 1:
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		case 2:
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		default:
			std::cout << formName << " does not exist" << std::endl;
			throw UnknownForm();
	}
	return nullptr;
}

Intern::~Intern() {

}

int Intern::check(const std::string *words, const std::string &formName) {
	std::string str = "";
	unsigned long i;
	for (i = 0; i < formName.length(); i++) {
		str += (tolower(formName[i]));
	}
	for (i = 0; i < 3; i++) {
		if (str.find(words[i]) != std::string::npos)
			return (i);
	}
	return (-1);
}

const char *Intern::UnknownForm::what() const throw() {
	return ("Unknown form");
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}