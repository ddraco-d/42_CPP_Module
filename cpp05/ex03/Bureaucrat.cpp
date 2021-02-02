/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:22:38 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/30 18:02:31 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):
	name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other):
	name(other.name)
{
	if (other.grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (other.grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = other.grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}
int Bureaucrat::getGrade() const
{
	return (this->grade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	this->grade = bureaucrat.grade;
	return (*this);
}

void Bureaucrat::incGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat's name is - " << bureaucrat.getName() << std::endl <<\
		"Grade is - " << bureaucrat.getGrade();
	return (out);
}

void Bureaucrat::signForm(Form &form) const
{
	if (form.isSigned())
	{
		std::cout << this->name << " cannot sign <" <<\
			form.getName() << "> because it is already filled\n";
	}
	else if (this->grade > form.getSignGrade())
	{
		std::cout << this->name << " cannot sign " << form.getName()
				<< " because bureaucrat's grade is too low." << std::endl;
	}
	form.beSigned(*this);
}

void Bureaucrat::executeForm(Form const &form) const
{
	if (!form.isSigned())
	{
		std::cout << this->name << " cannot execute " << form.getName()
				  << " because the form is unsigned." << std::endl;
	}
	else if (form.getExecGrade() < this->grade)
	{
		std::cout << this->name << " cannot execute " << form.getName()
				  << " because his grade is too low." << std::endl;
	}
	else
		std::cout << this->name << " executes " << form.getName() << std::endl;
	form.execute(*this);
}