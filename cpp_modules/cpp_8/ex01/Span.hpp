/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:31:48 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:31:49 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::exception;
using std::sort;
using std::begin;
using std::end;
using std::cerr;

class Span
{
public:
	Span();
	Span( const Span& cpy );
	Span( unsigned int N );
	struct StorageIsFull : public exception
	{
		const char * what() const throw();
	};
	struct NotFoundOrHaveaOne : public exception
	{
		const char * what() const throw();
	};
	Span& operator = ( const Span& obj );
	~Span();

	void addNumber( int nb );
	int shortestSpan( void );
	int longestSpan( void );

private:
	std::vector<int> vc;
	unsigned int len;
};

#endif