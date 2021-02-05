/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:11:48 by ddraco            #+#    #+#             */
/*   Updated: 2021/02/05 21:12:31 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <ctime>

class Span
{
private:
	std::vector<int> arr;
	unsigned int N;
	Span();
public:
	class MaxSizeError : public std::exception {
		virtual const char *what() const throw();
	};
	class NotEnoughElements : public std::exception {
		virtual const char *what() const throw();
	};
	class SpanNotFound : public std::exception {
		virtual const char *what() const throw();
	};
	Span(const Span& other);
	Span& operator=(const Span& other);
	virtual ~Span();
	Span(unsigned int N);
	void addNumber(int elem);
	int	shortestSpan() const;
	int	longestSpan() const;
	template <typename T>
	void	addNumber(T begin, T end) {
		if (std::distance(begin, end) + this->arr.size() > this->N)
			throw Span::MaxSizeError();
		this->arr.insert(this->arr.end(), begin, end);
	}
};


#endif