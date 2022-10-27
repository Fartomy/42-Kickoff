/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:24:57 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:47 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "Diamond.hpp"

int main(void)
{
	DiamondTrap dmd( "Target Puppet" );

	dmd.attack( "Smith" );
	cout << dmd.getHealth() << endl;
	dmd.takeDamage(70);
	cout << dmd.getHealth() << endl;
	dmd.beRepaired(5);
	cout << dmd.getHealth() << endl << dmd.getEngpoint() << endl;
	dmd.whoAmI();


	return 0;
}