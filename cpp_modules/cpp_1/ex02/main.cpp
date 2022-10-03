/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:33:03 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/03 16:33:04 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string	str = "HI THIS IS BRAIN";
	string*	s_ptr = &str;
	string&	s_ref = str;

	cout << &str << endl;
	cout << s_ptr << endl;
	cout << &s_ref << endl;

	cout << str << endl;
	cout << *s_ptr << endl;
	cout << s_ref << endl;

	return (0);
}