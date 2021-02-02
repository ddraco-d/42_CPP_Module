/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:46:34 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/17 14:54:29 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheStack(void)
{
	Pony Stack("Stack Pony", 5);
	Stack.tellSmth();
}

void ponyOnTheHeap(void)
{
	Pony *Heap;

	Heap = new Pony("Heap Pony", 7);
	Heap->tellSmth();
	delete Heap;
}

int main(void)
{
	std::cout << "Stack:" << std::endl;
	ponyOnTheStack();
	std::cout << "Heap:" << std::endl;
	ponyOnTheHeap();
	return (0);
}