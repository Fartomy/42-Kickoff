#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat( const Cat &cpy );

	Cat& operator = ( const Cat &obj );
	~Cat();

	void makeSound( void ) const;
	string getType( void ) const;

private:
	Brain *catBrn;
};

#endif