/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLosers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:40:58 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/06 18:40:59 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDLOSERS_HPP
#define SEDLOSERS_HPP

#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::stringstream;
using std::cerr;
class SedLosers
{
public:

	ofstream fot;
	ifstream fin;

	void	setFilename(string fn);
	void	setS1(string s);
	void	setS2(string s);

	string	getFilename(void);
	string&	getS1(void);
	string&	getS2(void);

private:
	string fileName;
	string s1;
	string s2;
};

string	copyFileContent(SedLosers& fn);
bool	sedLoserCheck(string& s1, string& s2);
void	pasteFileContent(SedLosers& fn, string& alFl);
string&	changeFileContent(SedLosers& fn, string& alFl);

#endif
