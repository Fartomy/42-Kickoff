/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:59:10 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/02 12:59:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Zombie
{
public:
	void	announce(void);
	void	set_name(string str)
	{
		name = str;
	}
	string	get_name()
	{
		return (name);
	}
	Zombie(){};
	Zombie(string name)
	{
		this->name = name;
	};
	~Zombie()
	{
		cout << name << ": Destroyed!" << endl;
	}
private:
	string name;
};

Zombie	*zombieHorde( int N, std::string name );

#endif
