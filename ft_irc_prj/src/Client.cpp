#include "../inc/Client.hpp"

Client::Client() : fullName(""), nick(""), data(""), channel(""), reply(""),
					nameStat(0), passwdStat(0), nickStat(0), isOpr(false) {};

Client::~Client(){};

string& Client::getFullName( void ) { return fullName; }
string &Client::getNick( void ) { return nick; }
string &Client::getName( void ) { return name; }
string &Client::getData( void ) { return data; }
string &Client::getChannel( void ) { return channel; }
string &Client::getReply( void ) { return reply; }
int Client::getNameStat( void ) { return nameStat; }
int Client::getPasswdStat( void ) { return passwdStat; }
int Client::getNickStat( void ) { return nickStat; }
bool Client::getIsOpr( void ) { return isOpr; }

void Client::setFullName( string name ) { fullName = name; }
void Client::setNick( string nick ) { this->nick = nick; }
void Client::setName( string name ) { this->name = name; }
void Client::setData( string data ) { this->data = data; }
void Client::setChannel( string chnl ) { channel = chnl; }
void Client::setReply( string reply ) { this->reply = reply; }
void Client::setNameStat( int nameStt ) { nameStat = nameStt; }
void Client::setPasswdStat( int passStt ) { passwdStat = passStt; }
void Client::setNickStat( int nickStt ) { nickStat = nickStt; }
void Client::setIsOpr( bool opr ) { isOpr = opr; }