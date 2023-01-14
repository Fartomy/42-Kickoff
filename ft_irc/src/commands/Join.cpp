//
// Created by Mehmet eren Akbulut on 1/8/23.
//

#include "../../inc/Commands.hpp"

int join(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data) {
    std::string channel;
    std::string nick;
    std::string message;
    std::string message2;
    std::vector<Client> chan_usrs;
    size_t i;

	if( usr[id - 1].getNickStat() == 0 || usr[id - 1].getNameStat() == 0 )
	{
		message = "You have not a nick or username!\r\n";
		SendMessage(message, pfd[id].fd);
		return 0;
	}
    i = 0;
    while (data[0] == ' ')
        data.erase(data.begin());
    if (data.find('#') != 0 || data.find(' ') != std::string::npos) {
        message = "475 " + usr[id - 1].getNick() + usr[id - 1].getData() + " :Cannot join channel\r\n";
        SendMessage(message, pfd[i].fd);
        return 0;
    }
    data.erase(data.begin());
    channel = data;
    usr[id - 1].setChannel(channel);
    i = 1;
    message = usr[id - 1].getReply() + " JOIN #" + channel + "\r\n";
    while (i < pfd.size()) {
        if (usr[i - 1].getChannel() == channel) {
            SendMessage(message, pfd[i].fd);
            chan_usrs.push_back(usr[i - 1]);
        }
        ++i;
    }
    message2 = ":ircserv 331 " + usr[id - 1].getNick() + " #" + channel + " :No topic is set\r\n";
    if (!chan_usrs.empty())
        message2 += ":ircserv 353 " + usr[id - 1].getNick() + " = #" + channel + " :@";
    if (chan_usrs.size() == 1)
        usr[id - 1].setIsOpr(1);
    i = 0;
    while (i < chan_usrs.size()) {
        message2 += chan_usrs[i].getNick();
        if (i == chan_usrs.size() - 1)
            message2 += "\r\n";
        else
            message2 += " ";
        ++i;
    }
    message2 += ":ircserv 366 " + usr[id - 1].getNick() + " #" + channel + " :End of /NAMES list\r\n";
    SendMessage(message2, pfd[id].fd);
    return 0;
}