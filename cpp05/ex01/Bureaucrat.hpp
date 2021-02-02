/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:13:38 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/30 18:05:23 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT
# include <iostream>
# include <string>
class Bureaucrat;
# include "Form.hpp"

class Bureaucrat
{
private:
	int grade;
	std::string const name;
	Bureaucrat();
public:
	
	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
	
	Bureaucrat &operator=(Bureaucrat const &bureaucrat);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat(std::string name, int grade);
	virtual ~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();
	void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif