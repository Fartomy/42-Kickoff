/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:19 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:11:20 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	cout << "-----------[Array Animals]-----------" << endl;
	for (int z = 0; z < 4; z++)
	{	
		cout << arr[z]->getType() << endl;
		arr[z]->makeSound();
	}
	cout << "-----------[Array Animals]-----------" << endl;
	cout << "-------[Normal Object Animals]-------" << endl;
	cout << j->getType() << endl;
	j->makeSound();
	cout << i->getType() << endl;
	i->makeSound();
	cout << "-------[Normal Object Animals]-------" << endl;
	for (int z = 0; z < 4; z++)
		delete arr[z];

	delete j;
	delete i;
	// do not leaks control
	return 0;
}