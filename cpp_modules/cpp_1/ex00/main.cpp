/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:04:58 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/01 17:04:59 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
	Zombie z_obj("Foo");
	z_obj.announce();

	Zombie *z_ptr = newZombie("Foo_ptr");
	randomChump("Soo_Foo");
	delete z_ptr;

	return (0);
}