/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:08:19 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/04 20:04:47 by ddraco           ###   ########.fr       */
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
	size_t length;
	T *arr;
public:
	class OutOfBoundsException: public std::exception {
		virtual const char* what() const throw() {
			return("Index out of bounds");
		}
	};
	virtual ~Array()
	{}
	Array() : length(0), arr(nullptr)
	{}
	Array(size_t n) : length(n) {
		arr = new T[n];
	}
	Array(Array<T> const &other) : length(0), arr(nullptr) {
		if (other.length > 0)
		{
			this->arr = new T[other.length];
			for (size_t i = 0; i < other.length; i++)
				this->arr[i] = other.arr[i];
		}
		this->length = other.length;
	}
	Array &operator=(Array const &other) {
		if (this->length > 0)
			delete[] this->arr;
		this->arr = nullptr;
		if (other.length > 0)
		{
			this->arr = new T[other.length]();
			for (size_t i = 0; i < other.length; i++)
				this->arr[i] = other.arr[i];
		}
		this->length = other.length;
		return (*this);
	}
	T &operator[](size_t index) {
		if (index >= this->length)
			throw Array::OutOfBoundsException();
		return (this->arr[index]);
	}
	T const &operator[](size_t index) const {
		return (operator[](index));
	}
	size_t size(void) const {
		return (this->length);
	}
};

#endif