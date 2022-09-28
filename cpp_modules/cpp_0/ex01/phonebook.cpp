#include "phonebook.hpp"

void	add_contact(PhoneBook *contacts)
{
	int i = -1;
	std::string secret_msg;

	while (++i < 8)
	{
		std::cout << "Enter Your Name:" << std::endl;
		std::cin >> contacts[i].first_name;
		while (!contacts[i].first_name[0])
		{
			std::cout << "Please do not leave blank!\nEnter Your Name:" << std::endl;
			std::cin >> contacts[i].first_name;
		}
		std::cout << "Enter Your Last Name:" << std::endl;
		std::cin >> contacts[i].last_name;
		while (!contacts[i].last_name[0])
		{
			std::cout << "Please do not leave blank!\nEnter Your Last Name:" << std::endl;
			std::cin >> contacts[i].last_name;
		}
		std::cout << "Enter Your Phone Number:" << std::endl;
		std::cin >> contacts[i].phone_number;
		while (!contacts[i].phone_number)
		{
			std::cout << "Please do not leave blank!\nEnter Your Phone Number:" << std::endl;
			std::cin >> contacts[i].phone_number;
		}
		std::cout << "Enter Your Darkest String:" << std::endl;
		std::cin >> secret_msg;
		while (!secret_msg[0])
		{
			std::cout << "Please do not leave blank!\nEnter Your Name:" << std::endl;
			std::cin >> secret_msg;
		}
		contacts[i].set_darkest_secret(secret_msg);
	}
	
}

void	welcome_to_phonebook(PhoneBook *contacts)
{
	std::string cmd;

	std::cout << "Please Type Command:\n1-ADD\n2-SEARCH\n3-EXIT" << std::endl;
	std::cin >> cmd;
	if (cmd == "ADD")
		add_contact(contacts);
/*    else if (cmd == "SEARCH")
		search_contact();*/
    else if (cmd == "EXIT")
		exit(1);
    else
	{
		std::cout << "Wrong Command! Please Retype.." << std::endl;
		welcome_to_phonebook(contacts);
	}
}



int main(void)
{
	PhoneBook contacts[8];

	while (1)
		welcome_to_phonebook(contacts);
	return (0);
}