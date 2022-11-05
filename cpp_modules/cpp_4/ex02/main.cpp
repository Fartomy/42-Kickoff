#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main ( void )
{

	//const Animal *obj1 = new Animal(); // We cannot define. Because Animal class have a pure virtual function.
	const Animal *obj2 = new Dog();
	const Animal *obj3 = new Cat();

	cout << obj2->getType() << endl;
	obj2->makeSound();

	cout << obj3->getType() << endl;
	obj3->makeSound();

	return 0;
}