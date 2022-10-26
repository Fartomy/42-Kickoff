/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:24:30 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/25 15:24:31 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap obj("Target Puppet");

	obj.attack("Furkan");
	cout << obj.getHealth() << endl;
	obj.takeDamage(1);
	obj.takeDamage(1);
	cout << obj.getHealth() << endl;
	obj.beRepaired(2);
	cout << obj.getHealth() << endl << obj.getEngpoint() << endl;

	return 0;
}