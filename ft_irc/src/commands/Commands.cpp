#include "../../inc/Commands.hpp"
#include "../../inc/ircserv.hpp"

Commands::Commands() {};

Commands::~Commands() {};

const std::string &Commands::getCommand() {
    return this->Command;
}

const std::string &Commands::getSubCmd() {
    return this->SubCmd;
}

const std::string &Commands::getMessage() {
    return this->Message;
}

void Commands::setCommand(const std::string &cmd) {
    this->Command = cmd;
}

void Commands::setSubCmd(const std::string &subCmd) {
    this->SubCmd = subCmd;
}

void Commands::setMessage(const std::string &Message) {
    this->Message = Message;
}

int Commands::EnterCommand(std::string &data, int id, std::vector<Client> &usr, std::vector<struct pollfd> &plFd) {
    int i = 0;

    const char *cmd[] = {
            "PRIVMSG",
            "JOIN",
            "PING",
            "NICK",
            "USER",
            "KICK",
			"QUIT",
			"NOTICE",
			"HELP",
            NULL
    };

    int (*cmdp[])(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data) =
    {
            &privmsg,
            &join,
            &ping,
            &nickname,
            &username,
            &kick,
			&quit,
			&notice,
			&help,
    };

    setSubCmd(data);
    if (data.find(' ') == std::string::npos) {
        setMessage("Invalid Command!\nCommand not found: " + getSubCmd() + "\n");
        send(plFd[id].fd , this->getMessage().data(), this->getMessage().length(), 0);
        return 0;
    }
    setCommand(data.substr(0, data.find(' ')));
    chrTrimer(data, ' ');
    std::cout << YLW << "Outcoming Command: " << getCommand() << RESET << std::endl;
    while (cmd[i]) {
        if (getCommand() == cmd[i])
            return cmdp[i](id, plFd, usr, data);
        ++i;
    }
    setMessage("Missing Command!\nCommand is missing: " + getSubCmd() + "\n");
    SendMessage(getMessage(), plFd[id].fd);
    return 0;
}

void chrTrimer(std::string &s, char ch) {
    s = s.substr(s.find(ch) + 1, s.length() - s.find(ch));
}

void	SendMessage(std::string message, int fd)
{
    std::cout << MAGEN << ">> [" << fd << "] << Client " << WHT << "taked from " <<
			GRN << "Server: " << YLW << message << RESET << std::endl;
    send(fd, message.data(),message.length(), 0);
}
