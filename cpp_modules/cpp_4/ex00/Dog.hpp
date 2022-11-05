#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog( const Dog &cpy );

	Dog& operator = ( const Dog &obj );
	~Dog();

	void makeSound( void ) const;
	string getType( void ) const;
};

#endif