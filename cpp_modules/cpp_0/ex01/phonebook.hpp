#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class PhoneBook
{
    public:
    std::string		first_name;
    std::string		last_name;

    int				phone_number;
    
    void			add_contact(PhoneBook *contacts);
	void			search_contact();

	/*Encapsulation*/
	void	set_darkest_secret(std::string str)
	{
		darkest_secret = str;
	}

	std::string get_darkest_secret()
	{
		return (darkest_secret);
	}
	/*Encapsulation*/
    private:
    std::string darkest_secret;

};

void	add_contact(PhoneBook *contacts);
void	search_contact();

#endif