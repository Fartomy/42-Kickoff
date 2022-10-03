/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:46:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/03 16:46:05 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon club = Weapon("C-98");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("Elwerici");
	bob.attack();

	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("Famas Gold");
	jim.attack();

	return (0);
}