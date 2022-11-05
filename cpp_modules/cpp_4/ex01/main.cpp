#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <stdlib.h>

int main ( void )
{
	int x = 0;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	Animal *arr[4];

	for (int z = 0; z < 2; z++)
		arr[x++] = new Cat();
	for (int z = 0; z < 2; z++)	
		arr[x++] = new Dog();
	for (int z = 0; z < 4; z++)
	{
		//arr[z]->getType();
		arr[z]->makeSound();
	}
	for (int z = 0; z < 4; z++)
		delete arr[z];

	delete j;
	delete i;
	
	return 0;
}