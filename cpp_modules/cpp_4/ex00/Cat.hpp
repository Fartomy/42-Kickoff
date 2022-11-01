#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &cpy);

	Cat& operator = ( const Cat &obj );
	~Cat();
private:

protected:
};

#endif