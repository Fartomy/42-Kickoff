/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:53:21 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/04 00:53:22 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLosers.hpp"

int main(int ac, char **av)
{
	if(ac == 4)
	{
		SedLosers	fn;

		fn.setFilename(char[1]);
		fn.setS1(char[2]);
		fn.setS2(char[3]);
	}
	else
		cout << "Wrong Number of Arguments!" << endl;

	return (0);
}