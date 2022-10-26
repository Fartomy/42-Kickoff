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
	ScavTrap scv( "Target Puppet" );

	scv.attack( "Gomes" );
	cout << scv.getHealth() << endl;
	scv.takeDamage( 30 );
	cout << scv.getHealth() << endl;
	scv.beRepaired( 20 );
	cout << scv.getHealth() << endl << scv.getEngpoint() << endl;
	scv.guardGate();

	return 0;
}