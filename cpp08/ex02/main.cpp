/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:14:22 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/05 22:46:48 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>

int	main(void) {
	std::cout << "______SUBJECT_CHECK___\n\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it_0 = mstack.begin();
	MutantStack<int>::iterator ite_0 = mstack.end();
	++it_0;
	--it_0;
	while (it_0 != ite_0)
	{
		std::cout << *it_0 << std::endl;
		++it_0;
	}
	std::stack<int> s(mstack);
	std::cout << "\n\n______ADDITIONAL_CHECK___\n\n";
	MutantStack<float> check;
	check.push(0.0);
	check.push(1.1);
	check.push(2.2);
	check.push(3.3);
	check.push(4.4);
	check.push(5.5);
	MutantStack<float> check2(check);
	MutantStack<float>::const_iterator it = check2.begin();
	MutantStack<float>::const_iterator ite = check2.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		it++;
	}
	it -= check2.size();
	std::cout << *it << std::endl;

	std::cout << std::endl;
	MutantStack<float>::const_reverse_iterator ret_iter1 = check.rbegin();
	MutantStack<float>::const_reverse_iterator ret_iter2 = check.rend();
	++ret_iter1;
	--ret_iter1;
	while (ret_iter1 != ret_iter2) {
		std::cout << *ret_iter1 << std::endl;
		ret_iter1++;
	}
	return 0;
}