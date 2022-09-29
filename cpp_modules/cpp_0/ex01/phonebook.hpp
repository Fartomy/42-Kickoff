#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class PhoneBook
{
    public:
    string	first_name;
	string	nick_name;
    string	last_name;
    string	phone_number;

	int		index;
	int		add_cnt;
	/*Encapsulation*/
	void	set_darkest_secret(std::string str)
	{
		darkest_secret = str;
	}

	string	get_darkest_secret()
	{
		return (darkest_secret);
	}
	/*Encapsulation*/
    private:
    string darkest_secret;

};

bool	isNumber(string nbr);
void	add_contact(PhoneBook *contacts);
void	search_contact(PhoneBook *contacts);
void	display_contact(PhoneBook *contacts, int i);

#endif