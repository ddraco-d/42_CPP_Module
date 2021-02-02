/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:09:03 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/02 20:24:16 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	int check(std::string const *words, std::string const &formName);
public:
	virtual ~Intern();
	class UnknownForm: public std::exception {
		virtual const char* what() const throw();
	};
	Intern();

	Form *make_form(std::string const &formName, std::string const &target);
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
};



#endif
