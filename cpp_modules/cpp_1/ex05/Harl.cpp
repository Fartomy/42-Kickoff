/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:19:36 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/06 23:19:37 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	fncPtr[0] = &Harl::debug;
	fncPtr[1] = &Harl::info;
	fncPtr[2] = &Harl::warning;
	fncPtr[3] = &Harl::error;
};

void	Harl::debug(void)
{
	cout << "[ DEBUG ]" << endl;
	cout << "I love having extra bacon for my"
			"XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << endl;
}

void	Harl::info(void)
{
	cout << "[ INFO ]" << endl;
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
			"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void	Harl::warning(void)
{
	cout << "[ WARNING ]" << endl;
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
			"years whereas you started working here since last month." << endl;
}

void	Harl::error(void)
{
	cout << "[ ERROR ]" << endl;
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void	Harl::complain(string level)
{
	int i = -1;
	bool check = false;
	string cmp[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (++i < 4 && check != true)
	{
		while (level == cmp[i])
		{
			check = true;
			i--;
			break;
		}
	}
	switch (i)
	{
		case 0 :
			(this->*fncPtr[0])();
			break;
		case 1 :
			(this->*fncPtr[1])();
			break;
		case 2 :
			(this->*fncPtr[2])();
			break;
		case 3 :
			(this->*fncPtr[3])();
			break;
		default :
			cout << "Harl says: Wrong Choice!" << endl;
	}
}