#include "Data.hpp"

Data::Data() : a( 10 ), ch( 'A' ), b( true ) {};

Data::Data( const Data& cpy )
{
    *this = cpy;
};

Data& Data::operator = ( const Data& obj )
{
	this->a = obj.a;
	this->b = obj.b;
	this->ch = obj.ch;
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