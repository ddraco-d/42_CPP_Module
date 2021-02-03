/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:18:04 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/03 22:41:32 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	void *raw = serialize();
	Data *data = deserialize(raw);
	std::cout << "\nAfter....\n\n";
	std::cout << data->s1 << '\n';
	std::cout << data->n << '\n';
	std::cout << data->s2 << '\n';
	delete data;
}
