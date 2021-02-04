/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:42:33 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/04 22:22:49 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

class Awesome 
{
public:
	Awesome( int n ) : _n( n ) {} 
	bool operator==( Awesome const & rhs ) const
	{
		return (this->_n == rhs._n);
	}
	bool operator!=(Awesome const & rhs) const
	{
		return (this->_n != rhs._n);
	}
	bool operator>(Awesome const & rhs) const 
	{
		return (this->_n > rhs._n);
	}
	bool operator<(Awesome const & rhs) const 
	{
		return (this->_n < rhs._n);
	} bool operator>=( Awesome const & rhs ) const 
	{
		return (this->_n >= rhs._n);
	}
	bool operator<=(Awesome const & rhs) const 
	{
		return (this->_n <= rhs._n);
	}
	int getN(void) {
		return (this->_n);
	}
private:
	int _n; 
};

int main( void ) {
	//Check-list
	Awesome x(20);
	Awesome y(120);
	
	::swap( x, y );
	std::cout << "x = " << x.getN() << ", y = " << y.getN() << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ).getN() << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ).getN( ) << std::endl;

	//Subject
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
