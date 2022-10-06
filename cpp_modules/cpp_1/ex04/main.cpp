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
	if (ac == 4)
	{
		SedLosers		sl;
		string			allFile;
		size_t			nb;

		sl.setFilename(av[1]);
		sl.setS1(av[2]);
		sl.setS2(av[3]);

		if(!sedLoserCheck(sl.getS1(), sl.getS2()))
		{
			cout << "Same Words!" << endl;
			return (1);
		}
		allFile = copyFileContent(sl);
		while ((nb = allFile.find(sl.getS1())) != string::npos)
		{
			allFile.erase(nb, sl.getS1().length());
			allFile.insert(nb, sl.getS2());
		}
		sl.fin.close();
		sl.setFilename(sl.getFilename() + ".replace");
		sl.fot.open(sl.getFilename());
		sl.fot << allFile << endl;
		sl.fot.close();
	}
	else
		cout << "Wrong Number of Arguments!" << endl;

	return (0);
}