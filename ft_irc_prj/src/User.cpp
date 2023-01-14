#include "../inc/Commands.hpp"

int username(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data)
{
	std::string my_data;
	std::string message;

	my_data = data;
	std::cout << "Username: " << my_data << std::endl;
	if (my_data.length() == 0 || usr[id - 1].getNickStat() == 0)
	{
		message = "Please first fill the nickname!\r\n";
		SendMessage(message, pfd[id].fd);
		return 0;
	}
	usr[id - 1].setNameStat(1);
	usr[id - 1].setName(my_data);
	usr[id - 1].getReply() = ":" + usr[id - 1].getNick() + "!" + usr[id - 1].getName() + "@127.0.0.1";
	message = ":ircserv 001 " + usr[id - 1].getNick() + " /***********[- WELCOME TO THE INTERNET RELAY CHAT SERVER -]***********\\ " \
 + usr[id - 1].getReply() + "\r\n";
	SendMessage(message, pfd[id].fd);
	return 0;
}