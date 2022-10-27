/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:24:30 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:16 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clp( "Pedro" );

	cout << endl;
	cout << "Name: " << clp.getName() << endl;
	cout << "Health: " << clp.getHealth() << endl;
	cout <<"Attack Damage Point: " << clp.getAtckDmg() << endl;
	cout << "Energy Point: " << clp.getEngpoint() << endl;
	cout << endl;

	clp.attack( "Gomes" );
	cout << "Health: " << clp.getHealth() << endl;
	clp.beRepaired( 2 );
	cout << "Health: " << clp.getHealth() << endl << "Energy Point: " << clp.getEngpoint() << endl;

	return 0;
}