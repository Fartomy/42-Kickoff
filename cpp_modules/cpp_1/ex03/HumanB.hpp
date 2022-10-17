/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:46:02 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/03 16:46:03 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;

class HumanB
{
public:

	HumanB();
	HumanB(string nm);
	void	attack(void);
	void	setName(string nm);
	void	setWeapon(Weapon &wp);
	string	getName(void);
	string	getWeapon(void);
private:
	string	name;
	Weapon* wpn;
};

#endif