/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedlosersUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:41:00 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/06 18:41:01 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLosers.hpp"

string	copyFileContent(SedLosers& fn)
{
	stringstream	buf;
	string			allFileCnt;

	fn.fin.open(fn.getFilename());
	if(fn.fin.fail())
	{
		cout << "File Failed to Open!" << endl;
		exit(1);
	}
	buf << fn.fin.rdbuf();
	allFileCnt = buf.str();
	if(!allFileCnt[0])
	{
		cout << "File is Empty!" << endl;
		exit (1);
	}
	return (allFileCnt);
}

bool	sedLoserCheck(string& s1, string& s2)
{
	if(s1 == s2)
		return (false);
	return (true);
}

void	pasteFileContent(SedLosers& fn, string& alFl)
{
	fn.setFilename(fn.getFilename() + ".replace");
	fn.fot.open(fn.getFilename());
	fn.fot << alFl << endl;
	fn.fot.close();
}

string&	changeFileContent(SedLosers& fn, string& alFl)
{
	size_t nb;

	while ((nb = alFl.find(fn.getS1())) != string::npos)
	{
		alFl.erase(nb, fn.getS1().length());
		alFl.insert(nb, fn.getS2());
	}
	fn.fin.close();

	return (alFl);
}