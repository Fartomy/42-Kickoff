/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:11:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/01 16:51:45 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	welcome_to_phonebook(PhoneBook &obj)
{
	string cmd;

	cout << "Please Type Command:\n1-ADD\n2-SEARCH\n3-EXIT" << endl;
	cin >> cmd;
	if (cmd == "ADD")
		obj.add_contact();
    else if (cmd == "SEARCH")
		obj.search_contact();
    else if (cmd == "EXIT")
		exit(1);
    else
		cout << "Wrong Command! Please Retype.." << endl;
}

int main(void)
{
	PhoneBook obj;
	
	cout << "*/ WELCOME TO THE PHONEBOOK-V1.2 \\*\n" << endl;
	while (1)
		welcome_to_phonebook(obj);
	return (0);
}