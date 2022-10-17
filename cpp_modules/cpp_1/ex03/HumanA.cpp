/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:45:54 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/03 16:45:55 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(void)
{
	cout << name << " attacks with their " << wpn->getType() << endl;
}

HumanA::HumanA(){};

HumanA::HumanA(string nm, Weapon& wp)
{
	wpn = &wp;
	name = nm;
};

void	HumanA::setName(string nm)
{
	name = nm;
}

void	HumanA::setWeapon(Weapon &wp)
{
	wpn = &wp;
}

string	HumanA::getName(void)
{
	return (name);
}

string 	HumanA::getWeapon(void)
{
	return (wpn->getType());
}