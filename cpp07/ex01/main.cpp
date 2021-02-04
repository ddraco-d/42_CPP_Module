/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:42:29 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/04 19:08:24 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome {
public:
Awesome( void ) : _n( 42 ) 
{
	return;
}
int get( void ) const 
{
	return this->_n;
}
private:
	int _n; 
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) 
{
	o << rhs.get();
	return o;
}

template< typename T >
void print( T const & x )
{
	std::cout << x << std::endl;
	return;
}
int main() 
{
	int arr1[5] = { 0, 1, 2, 3, 4 };
	iter(arr1, 5, &out);
	std::cout << std::endl;

	float arr2[5] = { 0.0f, 1.1f, 2.2f, 3.3f, 4.4f };
	iter(arr2, 5, &out);
	std::cout << std::endl;

	double arr3[5] = { 0.00, 1.11, 2.22, 3.33, 4.44 };
	iter(arr3, 5, &out);
	std::cout << std::endl;

	std::string arr5[5] = { "wrd1", "wrd2", "wrd3", "wrd4", "wrd5" };
	iter(arr5, 5, &out);
	std::cout << std::endl;
	
	std::cout << "\n\n_______Subject_Check________\n\n";
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );
	return 0;
}
