#include "Data.hpp"

Data::Data() : tmp("Temp") {};

Data::Data( const Data& cpy )
{
    *this = cpy;
};

void Data::temp( void )
{
    cout << temp << endl;
}

Data& Data::operator = ( const Data& obj )
{
    this->tmp = obj.tmp;
    return ( *this );
}

Data::~Data(){};

uintptr_t serialize( Data* ptr )
{
    uintptr_t tmp = reinterpret_cast<uintptr_t>( ptr );

    return tmp;
}

Data* deserialize( uintptr_t raw )
{
	Data *tmp = reinterpret_cast<Data *>( raw );
	
	return tmp;
}