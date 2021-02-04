/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:08:19 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/04 22:16:46 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>

template <typename T>
class Array
{
private:
	unsigned int length;
	T *arr;
public:
	class OutOfBoundsException: public std::exception {
		virtual const char* what() const throw() {
			return("Index out of bounds");
		}
	};
	virtual ~Array()
	{
		if (this->length > 0)
			delete[] this->arr;
	}
	Array() : length(0), arr(NULL)
	{}
	Array(unsigned int n) : length(n), arr(NULL) {
		this->arr = new T[n];
		for (unsigned int i = 0; i < n; i++)
			this->arr[i] = T();
	}
	Array(Array<T> const &other) : length(0), arr(NULL) {
		if (other.length > 0)
		{
			this->arr = new T[other.length]();
			for (unsigned int i = 0; i < other.length; i++)
				this->arr[i] = other.arr[i];
		}
		this->length = other.length;
	}
	Array &operator=(Array const &other) {
		if (this->length > 0)
			delete[] this->arr;
		this->arr = NULL;
		if (other.length > 0)
		{
			this->arr = new T[other.length]();
			for (unsigned int i = 0; i < other.length; i++)
				this->arr[i] = other.arr[i];
		}
		this->length = other.length;
		return (*this);
	}
	T &operator[](unsigned int index) {
		if (index >= this->length)
			throw Array::OutOfBoundsException();
		return (this->arr[index]);
	}
	T const &operator[](unsigned int index) const {
		return (operator[](index));
	}
	unsigned int size(void) const {
		return (this->length);
	}
};

#endif