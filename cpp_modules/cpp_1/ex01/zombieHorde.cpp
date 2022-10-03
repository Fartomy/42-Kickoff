/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:59:13 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/02 12:59:16 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, string name)
{
	Zombie *z_ptr;

	z_ptr = new Zombie[N];
	for (int i = 0; i < N; ++i)
		z_ptr[i].set_name(name);
	return (z_ptr);
}