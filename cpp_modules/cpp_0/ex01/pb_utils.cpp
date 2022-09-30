/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:17:01 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/30 19:56:59 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool	isNumber(string nbr)
{
	int i = -1;
	while (nbr[++i])
	{
		if(!isdigit(nbr[i]))
			return (false);
	}
	return (true);
}

string	shortener(string st)
{
	char str[11];
	int x = -1;
	int len;

	if(st.length() > 10)
	{
		while (++x <= 9)
		{
			if(x == 9)
			{
				str[x++] = '.';
				str[x] = 0;
				break ;
			}
			str[x] = st[x];
		}
		return (str);
	}
	else
	{
		len = st.length();
		len = 10 - len;
		while (st[++x])
			str[x] = st[x];
		while (len--)
			str[x++] = ' ';
		str[x] = 0;
		return (str);
	}
}

void	display_contact(PhoneBook *contacts, int i)
{
	cout << contacts[i].index << " | " << shortener(contacts[i].first_name) << \
			" | " << shortener(contacts[i].last_name) << " | " << shortener(contacts[i].nick_name) << endl;
}

void	search_contact(PhoneBook *contacts)
{
	int idx;
	int i = -1;

	if(contacts->add_cnt == 0)
	{
		cout << "No saved contacts! Please some save contact." << endl;
		return ;
	}
	while (++i < contacts->add_cnt)
		display_contact(contacts, i);
	i = -1;
	cout << "Please search contact index number:" << endl;
	cin >> idx;
	while (++i < contacts->add_cnt)
	{
		if(idx == contacts[i].index)
		{
			display_contact(contacts, i);
			return ;
		}
	}
	cout << "The contact not found!" << endl;
}

void	add_contact(PhoneBook *contacts)
{
	static int i = 0;
	string secret_msg;

    if(i >= 8)
    {
        cout << i + 1 << '-' << "Enter a Name:" << endl;
        cin >> contacts[(i - contacts->add_cnt)].first_name;
        cout << i + 1 << '-' << "Enter a Last Name:" << endl;
        cin >> contacts[(i - contacts->add_cnt)].last_name;
        cout << i + 1 << '-' << "Enter a Nick Name:" << endl;
        cin >> contacts[(i - contacts->add_cnt)].nick_name;
        cout << i + 1 << '-' << "Enter a Phone Number:" << endl;
        cin >> contacts[(i - contacts->add_cnt)].phone_number;
        while (!isNumber(contacts[i - contacts->add_cnt].phone_number))
	    {
		    cout << "Please type a number!\nEnter a Phone Number: ";
		    cin >> contacts[i - contacts->add_cnt].phone_number;
	    }
        cout << i + 1 << '-' << " Enter a Darkest Secret:" << endl;
	    cin >> secret_msg;
	    contacts[i - contacts->add_cnt].set_darkest_secret(secret_msg);
        contacts[i - contacts->add_cnt].index = (i - contacts->add_cnt) + 1;
        return ;
    }
	cout << i + 1 << '-' << " Enter a Name:" << endl;
	cin >> contacts[i].first_name;
	cout << i + 1 << '-' << " Enter a Last Name:" << endl;
	cin >> contacts[i].last_name;
	cout << i + 1 << '-' << " Enter a Nick Name:" << endl;
	cin >> contacts[i].nick_name;
	cout << i + 1 << '-' << " Enter a Phone Number:" << endl;
	cin >> contacts[i].phone_number;
	while (!isNumber(contacts[i].phone_number))
	{
		cout << "Please type a number!\nEnter a Phone Number: ";
		cin >> contacts[i].phone_number;
	}
	cout << i + 1 << '-' << " Enter a Darkest Secret:" << endl;
	cin >> secret_msg;
	contacts[i].set_darkest_secret(secret_msg);
	contacts[i].index = i + 1;
	contacts->add_cnt = i + 1;
	i++;
}