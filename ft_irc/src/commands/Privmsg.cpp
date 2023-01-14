//
// Created by Mehmet eren Akbulut on 1/8/23.
//

#include "../../inc/Commands.hpp"

int privmsg(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data) {
    std::string channel;
    std::string nick;
    std::string message;
    std::string to_send;
    std::string sub_cmd;
    size_t i;
    size_t cmp;
    i = 0;

	if( usr[id - 1].getNickStat() == 0 || usr[id - 1].getNameStat() == 0 )
	{
		message = "You have not a nick or username!\r\n";
		SendMessage(message, pfd[id].fd);
		return 0;
	}
    to_send = "";
    sub_cmd = data;
    while (data[0] == ' ')
        data.erase(data.begin());
    if (data.find('#') == 0)
    {
        data.erase(data.begin());
        if (data.find(' ') == std::string::npos)
        {
            message = ":ircserv 411 " + usr[id - 1].getNick() +" :No recipient given (" + sub_cmd + ")\r\n";
            SendMessage(message, pfd[id].fd);
            return 0;
        }
        channel = data.substr(0, data.find(' '));
        chrTrimer(data ,' ');
        while (data[0] == ' ')
            data.erase(data.begin());
        if (data[0] != ':')
        {
            message = ":ircserv 411 " + usr[id - 1].getNick() +" :No recipient given (" + sub_cmd + ")\r\n";
            SendMessage(message, pfd[id].fd);
            return 0;
        }
        data.erase(data.begin());
        if (usr[id - 1].getChannel() != channel)
        {
            message = ":ircserv 404 " + usr[id - 1].getNick() + " " + usr[id - 1].getChannel() + " :Cannot send to channel!\r\n";
            SendMessage(message, pfd[id].fd);
            return 0;
        }
        message = data.substr(0, data.find('\n'));
        cmp = id;
        i = 1;
        while(i < pfd.size())
        {
            if (usr[i - 1].getChannel() == channel && cmp != i)
            {
                to_send = usr[id - 1].getReply() + " PRIVMSG #" + channel + " :" + message +"\r\n";
                SendMessage(to_send, pfd[i].fd);
            }
            ++i;
        }
        return 0;
    }
    else
    {
        if (data.find(' ') == std::string::npos)
        {
            message = ":ircserv 411 " + usr[id - 1].getNick() + " :No recipient given (" + sub_cmd + ")\r\n";
            SendMessage(message, pfd[id].fd);
            return 0;
        }
        nick = data.substr(0, data.find(' '));
        chrTrimer(data ,' ');
        while (data[0] == ' ')
            data.erase(data.begin());
        if (data[0] != ':')
        {
            message = ":ircserv 411 " + usr[id - 1].getNick() + " :No recipient given (" + sub_cmd + ")\r\n";
            SendMessage(message, pfd[id].fd);
            return 0;
        }
        data.erase(data.begin());
        message = data;
        if (message.length() < 1)
        {
            message = ":ircserv 412 " + usr[id - 1].getNick() + " :Cannot to send! [no text]\r\n";
            SendMessage(message, pfd[id].fd);
            return 0;
        }
        i = 1;
        while (i < pfd.size())
        {
            if (usr[i - 1].getNick() == nick)
            {
                message = usr[id - 1].getReply() + " PRIVMSG " + nick + " :" + message +"\r\n";
                SendMessage(message, pfd[i].fd);
                return 0;
            }
            ++i;
        }
        message = ":ircserv 401 " + usr[id - 1].getNick() + " " + nick + " :Nick or channel not found!\r\n";
        SendMessage(message, pfd[id].fd);
        return 0;
    }
    return 0;
}