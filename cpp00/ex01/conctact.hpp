/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conctact.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:15:44 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/16 19:04:08 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>
class contact
{
private:
	static std::string	fields[11];
	std::string			information[11];
public:
	bool add();
	void look(void);
	std::string* get_info();
};

#endif