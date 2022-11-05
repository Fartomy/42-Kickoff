#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Animal
{
public:
	Animal();
	Animal( const Animal& cpy );

	virtual ~Animal();
	Animal& operator = (const Animal &obj);

	virtual void makeSound( void ) const = 0;
	virtual string getType( void ) const;

protected:
	string type;
};


#endif