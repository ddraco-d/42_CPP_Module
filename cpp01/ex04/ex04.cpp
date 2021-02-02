/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:49:36 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/18 14:52:23 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string s = "HI THIS IS BRAIN";
	std::string *pointer = &s;
	std::string &reference = s;
	std::cout << "Pointer: " << *pointer << std::endl;
	std::cout << "Reference: " << reference << std::endl;
	return 0;
}
