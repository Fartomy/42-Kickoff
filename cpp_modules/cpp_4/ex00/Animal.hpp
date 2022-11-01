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

	~Animal();
	Animal& operator = (const Animal &obj);

private:

protected:
	string type;
};


#endif