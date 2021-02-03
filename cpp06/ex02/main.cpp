/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:36:30 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/03 22:40:34 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <random>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate(void)
{
	int r = rand() % 3;

	switch (r)
	{
	case 0:
		std::cout << "A generated\n";
		return (new A);	
	case 1:
		std::cout << "B generated\n";
		return (new B);	
	case 2:
		std::cout << "C generated\n";
		return (new C);	
	default:
		break;
	}
	return (nullptr);
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C";
}

void identify_from_reference(Base &p)
{
	identify_from_pointer(&p);
}

int main(void)
{
	srand(time(NULL));
	Base *check = generate();
	identify_from_pointer(check);
	std::cout << ", ";
	identify_from_reference(*check);
	std::cout << std::endl;
	delete check;
	return (0);
}
