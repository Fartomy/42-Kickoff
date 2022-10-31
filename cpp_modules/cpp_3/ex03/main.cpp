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
	DiamondTrap dmd( "Angela" );

	cout << endl;
	cout << "Name: " << dmd.getName() << endl;
	cout << "Health: " << dmd.getHealth() << endl;
	cout << "Attack Damage Point: " << dmd.getAtckDmg() << endl;
	cout << "Energy Point: " << dmd.getEngpoint() << endl;
	cout << endl;

	dmd.attack( "Mao" );
	cout << "Health: " << dmd.getHealth() << endl;
	dmd.beRepaired( 2 );
	cout << "Health: " << dmd.getHealth() << endl << "Energy Point: " << dmd.getEngpoint() << endl;
	dmd.whoAmI();

	// virtual inhetaince keyword'u arastir, -WShadow vb. flag'lere bak
	return 0;
}