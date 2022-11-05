#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &cpy);

    WrongAnimal& operator = ( const WrongAnimal &obj );
    ~WrongAnimal();

    void makeSound( void ) const;
    string  getType( void ) const;

protected:
    string type;
};

#endif