/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:11:46 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/05 21:06:11 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span()
{
	this->arr.clear();
}

Span::Span(unsigned int N) : N(N) 
{}

void Span::addNumber(int elem) {
	if (this->arr.size() >= this->N )
		throw Span::MaxSizeError();
	this->arr.push_back(elem);
}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other)
	{
		this->N = other.N;
		this->arr = other.arr;
	}
	return *this;
}

int Span::shortestSpan() const
{
	int shortest;
	bool is_short = 0;
	if (this->arr.size() <= 1)
		throw Span::NotEnoughElements();
	std::vector <int> tmp(arr.size());
	std::copy(arr.begin(), arr.end(), tmp.begin());
	std::sort(tmp.begin(), tmp.end());
	shortest = tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < shortest)
		{
			shortest = tmp[i] - tmp[i - 1];
			is_short = 1;
		}
	}
	if (is_short == 0)
		throw Span::SpanNotFound();
	return (shortest);
}

int Span::longestSpan() const
{
	if (this->arr.size() <= 1)
		throw Span::NotEnoughElements();
	int min_elem = *std::min_element(arr.begin(), arr.end());
	int max_elem = *std::max_element(arr.begin(), arr.end());
	if (!(max_elem - min_elem))
		throw Span::SpanNotFound();
	return (max_elem - min_elem);
}

const char* Span::SpanNotFound::what() const throw()
{
	return "Span not found";
}

const char* Span::MaxSizeError::what() const throw()
{
	return "Error, max size reached";
}

const char* Span::NotEnoughElements::what() const throw()
{
	return "Not enough elements";
}