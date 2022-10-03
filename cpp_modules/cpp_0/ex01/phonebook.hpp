/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:16:57 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/01 17:04:14 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class	Contact
{
public:
	/*Encapsulation*/
	void	set_first_name(string str)
	{
		first_name = str;
	}
	string	get_first_name()
	{
		return (first_name);
	}
	void	set_last_name(string str)
	{
		last_name = str;
	}
	string	get_last_name()
	{
		return(last_name);
	}
	void	set_nick_name(string str)
	{
		nick_name = str;
	}
	string	get_nick_name()
	{
		return (nick_name);
	}
	void	set_phone_number(string str)
	{
		phone_number = str;
	}
	string	get_phone_number()
	{
		return(phone_number);
	}
	void	set_darkest_secret(string str)
	{
		darkest_secret = str;
	}
	string	get_darkest_secret()
	{
		return (darkest_secret);
	}
	void	set_index(int idx)
	{
		index = idx;
	}
	int		get_index()
	{
		return(index);
	}
	/*Encapsulation*/
private:

	int		index;
    string	first_name;
    string	last_name;
	string	nick_name;
    string	phone_number;
    string 	darkest_secret;
};

class PhoneBook
{
public:

	void	add_contact();
	void	search_contact();

	PhoneBook()
	{
		add_cnt = 0;	
	};
	Contact& get_contact(int index)
	{
		return (contact[index]);
	} 
private:

	Contact contact[8];
	int		add_cnt;
};

bool	isNumber(string nbr);
void	display_contact(PhoneBook *ph, int i);

#endif