#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Data
{
public:
    Data();
    Data( const Data &cpy );
    Data& operator = ( const Data& obj );
    ~Data();

    void temp( void );
private:
    string tmp;
};

uintptr_t serialize( Data* ptr );
Data* deserialize( uintptr_t raw );

#endif
