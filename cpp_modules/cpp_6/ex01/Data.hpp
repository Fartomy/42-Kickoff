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
	int a;
	char ch;
	bool b;
};

uintptr_t serialize( Data* ptr );
Data* deserialize( uintptr_t raw );

#endif
