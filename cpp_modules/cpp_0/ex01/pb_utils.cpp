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
		return (st);
}

void	display_contact(PhoneBook *contacts, int i)
{
	cout << contacts[i].index << " | " << shortener(contacts[i].first_name) << \
			" | " << shortener(contacts[i].last_name) << " | " << shortener(contacts[i].nick_name) << endl;
}

void	search_contact(PhoneBook *contacts)
{
	string str;
	int i = -1;

	if(contacts->add_cnt == 0)
	{
		cout << "No saved contacts! Please some save contact." << endl;
		return ;
	}
	while (++i < contacts->add_cnt)
		display_contact(contacts, i);
	i = -1;
	cout << "Please search a contact name, last name or nickname:" << endl;
	cin >> str;
	while (++i < contacts->add_cnt)
	{
		if(str == contacts[i].first_name)
		{
			display_contact(contacts, i);
			return ;
		}
		else if(str == contacts[i].last_name)
		{
			display_contact(contacts, i);
			return ;
		}
		else if(str == contacts[i].nick_name)
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