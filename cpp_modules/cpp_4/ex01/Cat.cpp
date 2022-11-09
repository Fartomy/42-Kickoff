/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:59 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:11:00 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    cout << "Cat default constructor called" << endl;
    type = "Cat";
    catBrn = new Brain();
}

Cat::Cat( const Cat &cpy ) : Animal()
{
    cout << "Cat copy constructor called" << endl;
    *this = cpy;
}

Cat::~Cat() 
{
    cout << "Cat destructor called" << endl;
    delete catBrn; 
}

Cat& Cat::operator = ( const Cat &obj )
{
    this->type = obj.type;
    return ( *this );
}

void Cat::makeSound( void ) const { cout << "Meeeooowww!" << endl; }


string Cat::getType( void ) const { return ( type ); }