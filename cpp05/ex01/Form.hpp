/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:59:11 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/30 17:53:47 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
class Form;
# include "Bureaucrat.hpp"

class Form
{
private:
	Form();
	std::string const name;
	bool is_signed;
	int const sign_grade;
	int const exec_grade;
public:
	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class AlreadySigned: public std::exception
	{
		virtual const char* what() const throw();
	};

	virtual ~Form();
	Form(std::string const &name, int const signGrade, int const executeGrade);
	Form(Form const &other);
	std::string const &getName(void) const;
	bool isSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	void beSigned(Bureaucrat const &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, Form const &form);


#endif