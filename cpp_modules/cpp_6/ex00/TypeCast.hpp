/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeCast.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:28:27 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:28:28 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECAST_HPP
#define TYPECAST_HPP

#include <iostream>
#include <limits.h>
#include <float.h>

using std::cout;
using std::endl;
using std::string;
using std::stof;
using std::stod;
using std::stoi;
using std::stold;
using std::exception;
using std::cerr;

class TypeCast
{
public:
	TypeCast();
	TypeCast( const TypeCast &cpy );

	struct ErrorHandle : public exception
	{
		const char * what() const throw();
	};

	TypeCast& operator = ( const TypeCast &obj );
	~TypeCast();
	void display( int a, char *ch );

private:
	string type;
};

bool	is_dotZeroD( char *ch );
bool	is_dotZeroF( char *ch );
int		which_type( char *ch );
bool	is_double( char *ch );
bool	is_float( char *ch );
bool	is_int( char *ch );

#endif