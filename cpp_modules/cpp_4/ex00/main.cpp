#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main ( void )
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *x = new WrongCat();

	cout << "-----------------------------------------------------------------" << endl;

	cout << j->getType() << " " << endl;
	cout << i->getType() << " " << endl;
	cout << meta->getType() << " " << endl;
	cout << x->getType() << " " << endl;

	cout << "-----------------------------------------------------------------" << endl;

	x->makeSound();
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete x;
	
	return 0;
}