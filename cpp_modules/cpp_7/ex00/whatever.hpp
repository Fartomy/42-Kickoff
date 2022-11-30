/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:26:37 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/30 17:26:38 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template< typename T > void swap( T& a, T& b )
{
	T temp = a;

	a = b;
	b = temp;
}

template< typename T > T& min( T& a, T& b )
{
	if( a < b )
		return a;
	else if( b < a )
		return b;
	else
		return b;
}

template< typename T > T& max( T& a, T& b )
{
	if( a > b )
		return a;
	else if( b > a )
		return b;
	else
		return b;
}

#endif