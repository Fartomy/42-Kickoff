/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:33:21 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:33:22 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft
{
	template <bool Cond, class T = void> struct enable_if
	{};
	template<class T> struct enable_if<true, T>
	{
		typedef T type;
	};
};

// https://cplusplus.com/reference/type_traits/enable_if/

#endif