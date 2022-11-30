/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:26:39 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/30 17:26:40 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;

template< typename T > void iter( T* arr,  size_t len, void (*fnc)(T const& itr))
{
	size_t i = 0;

	while( i < len )
		fnc( arr[i++] );
}

#endif