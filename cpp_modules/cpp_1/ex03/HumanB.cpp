/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:45:59 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/03 16:46:00 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack(void)
{
	cout << name << " attacks with their " << wpn->getType() << endl;
}

HumanB::HumanB(){};

HumanB::HumanB(string nm)
{
	setName(nm);
};

void	HumanB::setName(string nm)
{
	name = nm;
}

void	HumanB::setWeapon(Weapon &wp)
{
	wpn = &wp;
}

string	HumanB::getName(void)
{
	return (name);
}

string	HumanB::getWeapon(void)
{
	return (wpn->getType());
}