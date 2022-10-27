/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:24:57 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:26 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scv( "Christopher" );

	cout << endl;
	cout << "Name: " << scv.getName() << endl;
	cout << "Health: " << scv.getHealth() << endl;
	cout <<"Attack Damage Point: " << scv.getAtckDmg() << endl;
	cout << "Energy Point: " << scv.getEngpoint() << endl;
	cout << endl;

	scv.attack( "Smith" );
	cout << "Health: " << scv.getHealth() << endl;
	scv.beRepaired( 2 );
	cout << "Health: " << scv.getHealth() << endl << "Energy Point: " << scv.getEngpoint() << endl;
	scv.guardGate();

	return 0;
}