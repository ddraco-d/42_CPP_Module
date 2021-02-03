/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:24:53 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/03 20:25:39 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"
#include <iostream>
int main(int argc, char const **argv)
{
	if (argc != 2)
		std::cout << "wrong amount of args\n";
	else
	{
		Cast p(argv[1]);
		std::cout << p;
	}
	return (0);
}
