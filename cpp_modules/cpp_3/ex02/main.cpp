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

int main(void)
{
	FragTrap frg( "Adriana" );

	cout << endl;
	cout << "Name: " << frg.getName() << endl;
	cout << "Health: " << frg.getHealth() << endl;
	cout <<"Attack Damage Point: " << frg.getAtckDmg() << endl;
	cout << "Energy Point: " << frg.getEngpoint() << endl;
	cout << endl;

	frg.attack( "Tenorio" );
	cout << "Health: " << frg.getHealth() << endl;
	frg.beRepaired( 2 );
	cout << "Health: " << frg.getHealth() << endl << "Energy Point: " << frg.getEngpoint() << endl;
	frg.highFivesGuys();

	return 0;
}