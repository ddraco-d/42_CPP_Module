/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:19:21 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/30 19:36:49 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string const ShrubberyCreationForm::trees[2] =
{
"  		 /\\      \n"
"        /\\*\\      \n"
"       /\\O\\*\\     \n"
"      /*/\\/\\/\\    \n"
"     /\\O\\/\\*\\/\\   \n"
"    /\\*\\/\\*\\/\\/\\  \n"
"   /\\O\\/\\/*/\\/O/\\ \n"
"      	 || \n"
"		 ||\n"
"		 ||\n" ,
"         v\n" \
"        >X<\n" \
"         A\n" \
"        d$b\n" \
"      .d\\$$b.\n" \
"    .d$i$$\\$$b.\n" \
"       d$$@b\n" \
"      d\\$$$ib\n" \
"    .d$$$\\$$$b\n" \
"  .d$$@$$$$\\$$ib.\n" \
"      d$$i$$b\n" \
"     d\\$$$$@$b\n" \
"  .d$@$$\\$$$$$@b.\n" \
".d$$$$i$$$\\$$$$$$b.\n" \
"        ###\n" \
"        ###\n" \
"        ###\n"
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	Form("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	Form(other), target(other.target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	(void)other;
	return (*this);
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "Shrubbery - Cannot open file";
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	srand(time(NULL));
	std::ofstream fout((this->target + "_shrubbery"));
	int tree_amount = (rand() % 5) + 1;

	if (!fout.is_open())
		throw FileOpenException();
	for (int i = 0; i < tree_amount; i++)
		fout << ShrubberyCreationForm::trees[rand() % 2];
	fout << std::endl;
	fout.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}
