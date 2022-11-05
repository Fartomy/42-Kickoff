#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    cout << "WrongCat default constructor called" << endl;
    type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &cpy ) : WrongAnimal()
{
    cout << "WrongCat copy constructor called" << endl;
    *this = cpy;
}

WrongCat::~WrongCat(){ cout << "WrongCat destructor called" << endl; }

WrongCat& WrongCat::operator = ( const WrongCat &obj )
{
    type = obj.type;
    return ( *this );
}

void WrongCat::makeSound( void ) const { cout << "Weeeeeeooooowwww!" << endl; }

string WrongCat::getType( void ) const { return ( type ); }