/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:19:55 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/06 23:19:56 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if(ac == 2)
	{
		Harl	obj;
		string	msg = av[1];
		obj.complain(msg);
		return (0);
	}
	else
		cout << "Wrong Number of Arguments!" << endl;
}