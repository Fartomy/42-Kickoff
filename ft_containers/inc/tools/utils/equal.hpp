/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:33:23 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:33:24 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft
{
	template <class InputIterator1, class InputIterator2> bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if(*first1 == *first2)
			{
				first1++;
				first2++;
			}
			else
				return ( false );
		}
		return ( true );
	}
};

// https://cplusplus.com/reference/algorithm/equal/

#endif