/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:45:57 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/03 16:45:58 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;

class HumanA
{
public:
	HumanA(){};
	HumanA(string nm, Weapon wp)
	{
		wpn = wp;
		name = nm;
	};

	void	attack(void);

	void	setName(string nm)
	{
		name = nm;
	}
	void	setWeapon(Weapon wp)
	{
		wpn = wp;
	}

	string	getName(void)
	{
		return (name);
	}
	string 	getWeapon(void)
	{
		return (wpn.getType());
	}
private:
	string name;
	Weapon wpn;
};


#endif