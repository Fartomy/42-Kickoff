#include "Dog.hpp"

Dog::Dog()
{
    cout << "Dog default constructor called" << endl;
    type = "Dog";
}

Dog::Dog( const Dog &cpy ) : Animal()
{
    cout << "Dog copy constructor called" << endl;
    *this = cpy;
}

Dog::~Dog() { cout << "Dog destructor called" << endl; }

Dog& Dog::operator = ( const Dog &obj )
{
    type = obj.type;
    return ( *this );
}

void Dog::makeSound( void ) const { cout << "Woooooooooooof!" << endl; }

string Dog::getType( void ) const { return ( type ); }