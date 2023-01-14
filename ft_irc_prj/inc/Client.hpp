#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

using std::string;

class Client
{
public:
    Client();
    ~Client();

    string& getFullName( void );
    string& getNick( void );
    string& getData( void );
    string& getChannel( void );
    string& getReply( void );
    string& getName( void );
    int getNameStat( void );
    int getPasswdStat( void );
    int getNickStat( void );
    bool getIsOpr( void );

    void setFullName( string name );
    void setNick( string nick );
    void setName( string nick );
    void setData( string data );
    void setChannel( string chnl );
    void setReply( string reply );
    void setNameStat( int nameStt );
    void setPasswdStat( int passStt );
    void setNickStat( int nickStt );
    void setIsOpr( bool opr );

private:
    string fullName;
    string nick;
    string name;
    string data;
    string channel;
    string reply;
    int nameStat;
    int passwdStat;
    int nickStat;
    bool isOpr;

};

#endif
