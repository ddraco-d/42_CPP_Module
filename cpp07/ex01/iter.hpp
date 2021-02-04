/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:42:31 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/04 19:07:09 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>

template<typename T>
void iter(T *arr, size_t length, void (*f)(T const &elem))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

template<typename T>
void out(const T &elem)
{
	std::cout << elem << std::endl;
}


#endif