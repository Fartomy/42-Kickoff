/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:24:57 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/25 15:24:58 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap obj("Target Puppet");
	ScavTrap obj2("Taget Puppet2");

	obj.attack("Furkan");
	cout << obj.getHealth() << endl;
	obj.takeDamage(1);
	obj.takeDamage(1);
	cout << obj.getHealth() << endl;
	obj.beRepaired(2);
	cout << obj.getHealth() << endl << obj.getEngpoint() << endl;

	obj2.attack("Ali Furkan");
	obj2.guardGate();

	return 0;
}