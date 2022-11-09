/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:09:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:09:54 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() 
{
    cout << "Animal default constructor called" << endl;
    type = "Anymal";
}

Animal::Animal( const Animal &cpy )
{
    cout << "Animal copy constructor called" << endl;
    *this = cpy;
}

Animal::~Animal() { cout << "Animal destructor called" << endl; }

Animal& Animal::operator = ( const Animal &obj )
{
    this->type = obj.type;
    return *this;
}

void Animal::makeSound( void ) const
{
    cout << "ArghhMeoWoof.. This sound can be the sound of anymal." << endl;
}

string Animal::getType( void ) const { return ( type ); }