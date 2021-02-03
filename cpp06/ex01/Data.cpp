/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:02:03 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/03 22:20:10 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data *data_init(void)
{
	srand(time(NULL));
	Data *data = new Data();
	std::string alphabet = "0123456789" \
		"abcdefghijklmopqrstuvxyz" \
		"ABCDEFGHIJKLMOPQRSTUVXYZ";
	data->s1 = "";
	data->s2 = "";
	for (size_t i = 0; i < 8; i++)
	{
		data->s1 += alphabet[rand() % alphabet.length() - 1];
		data->s2 += alphabet[rand() % alphabet.length() - 1];
	}
	data->n = rand();
	return (data);
}

void *serialize(void)
{
	Data *data = data_init();
	std::cout << "In the beggining\n" << data->s1 << std::endl\
		<< data->n << std::endl << data->s2 << std::endl;
	return (reinterpret_cast<void *>(data));
}

Data *deserialize(void *raw)
{
	Data *d = reinterpret_cast<Data *>(raw);
	return (d);
}