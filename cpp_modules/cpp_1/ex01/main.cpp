/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:59:05 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/02 12:59:06 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *z_obj;
	z_obj = zombieHorde(5, "Foo");

	for (int i = 0; i < 5; ++i)
		z_obj[i].announce();
	delete[] z_obj;
	return (0);
}