/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:05:10 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/01 17:05:11 by ftekdrmi         ###   ########.fr       */
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
	string	get_name(void)
	{
		return (name);
	}
	Zombie(){}; // Default Constrctr
	Zombie(string name)
	{
		this->name = name;
	};
	~Zombie()
	{
		cout << name << " destroyed" << endl;
	};

private:
	string	name;
};

Zombie	*newZombie(string name);
void	randomChump(string name);

#endif