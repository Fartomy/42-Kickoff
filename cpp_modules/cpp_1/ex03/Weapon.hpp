/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:46:08 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/03 16:46:09 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Weapon
{
public:
	Weapon();
	Weapon(string nm);
	void			setType(string nm);
	const string&	getType(void);
private:
	string type;
};

#endif