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
	FragTrap frg( "Target Puppet" );

	frg.attack( "Christopher" );
	cout << frg.getHealth() << endl;
	frg.takeDamage(70);
	cout << frg.getHealth() << endl;
	frg.beRepaired(5);
	cout << frg.getHealth() << endl << frg.getEngpoint() << endl;
	frg.highFivesGuys();

	return 0;
}