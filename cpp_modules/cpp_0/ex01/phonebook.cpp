#include "phonebook.hpp"

void	welcome_to_phonebook(PhoneBook *contacts)
{
	string cmd;

	cout << "Please Type Command:\n1-ADD\n2-SEARCH\n3-EXIT" << endl;
	cin >> cmd;
	if (cmd == "ADD")
		add_contact(contacts);
    else if (cmd == "SEARCH")
		search_contact(contacts);
    else if (cmd == "EXIT")
		exit(1);
    else
		cout << "Wrong Command! Please Retype.." << endl;
}

int main(void)
{
	PhoneBook contacts[8];

	cout << "*/ WELCOME TO THE PHONEBOOK-V1.2 \\*\n" << endl;
	while (1)
		welcome_to_phonebook(contacts);
	return (0);
}