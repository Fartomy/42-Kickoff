#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    cout << "WrongAnimal default constructor called" << endl;
    type = "WrongAnymal";
}

WrongAnimal::WrongAnimal( const WrongAnimal &cpy )
{
    cout << "WrongAnimal copy constructor called" << endl;
    *this = cpy;
}

WrongAnimal& WrongAnimal::operator = ( const WrongAnimal &obj )
{
    type = obj.type;
    return ( *this );
}

WrongAnimal::~WrongAnimal() { cout << "WrongAnimal destructor called" << endl; }


void WrongAnimal::makeSound( void ) const
{
    cout << "ArghhMeoWoof.. This sound can be the sound of WrongAnymal." << endl;
}

string WrongAnimal::getType( void ) const { return ( type ); }