/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:26:45 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/05 15:30:44 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <string>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
	typename T::iterator found = std::find(container.begin(), container.end(), val);
	if (found == container.end())
		throw std::runtime_error("Element not found");
	return(found);
}

#endif