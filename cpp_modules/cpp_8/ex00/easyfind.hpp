/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:31:35 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:31:36 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::begin;
using std::end;
using std::exception;

struct Mistake : public exception
{
	const char * what() const throw()
	{
		return "Not Found!";
	}
};

template<typename T> typename T::iterator easyfind( T t, int i )
{
	typename T::iterator itr;
	for ( itr = t.begin(); itr < t.end(); ++itr )
	{
		if( *itr == i )
			return itr;
	}
	throw Mistake();
}

#endif