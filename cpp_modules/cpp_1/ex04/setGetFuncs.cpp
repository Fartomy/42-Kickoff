/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setGetFuncs.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:41:03 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/06 18:41:04 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLosers.hpp"

void	SedLosers::setFilename(string fn)
{
	fileName = fn;
}
void	SedLosers::setS1(string s)
{
	s1 = s;
}
void	SedLosers::setS2(string s)
{
	s2 = s;
}

string	SedLosers::getFilename(void)
{
	return (fileName);
}
string&	SedLosers::getS1(void)
{
	return (s1);
}
string&	SedLosers::getS2(void)
{
	return (s2);
}