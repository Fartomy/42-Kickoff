#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat( const WrongCat &cpy );

    WrongCat& operator = ( const WrongCat &obj );
    ~WrongCat();
    void makeSound( void ) const;
    string getType( void ) const;
};

#endif