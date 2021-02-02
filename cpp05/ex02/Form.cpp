/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:59:12 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/30 17:55:01 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

const char *Form::UnsignedException::what() const throw()
{
	return ("Form is unsigned");
}

Form::Form(std::string const &name, int const signGrade, int const executeGrade):
	name(name), is_signed(false), sign_grade(signGrade), exec_grade(executeGrade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &other):
	name(other.name), is_signed(other.is_signed),\
		sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

std::string const &Form::getName(void) const
{
	return (this->name);
}

bool Form::isSigned(void) const
{
	return (this->is_signed);
}

int Form::getSignGrade(void) const
{
	return (this->sign_grade);
}

int Form::getExecGrade(void) const
{
	return (this->exec_grade);
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	std::string signStatus;
	signStatus = (form.isSigned()) ? "Signed" : "Unsigned";
	out << "Name is - " << form.getName() << " Status of signing - " <<\
		signStatus << "\nSign_grade - " << form.getSignGrade() <<\
			" Executable_grade - " << form.getExecGrade();
	return (out);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->sign_grade)
		throw Form::GradeTooLowException();
	else if (this->is_signed)
		throw Form::AlreadySignedException();
	else
	{
		std::cout << bureaucrat.getName() << " signs <" <<\
			this->name << ">\n";
		this->is_signed = true;
	}
}

void Form::execute(const Bureaucrat &bureaucrat) const {
	if (bureaucrat.getGrade() > this->exec_grade)
		throw Form::GradeTooLowException();
	if (this->is_signed == false)
		throw Form::UnsignedException();
}

Form::~Form()
{
}
