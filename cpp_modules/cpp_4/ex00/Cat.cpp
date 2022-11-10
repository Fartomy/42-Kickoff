/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:01 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:10:02 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    cout << "Cat default constructor called" << endl;
    type = "Cat";
}

Cat::Cat( const Cat &cpy )
{
    cout << "Cat copy constructor called" << endl;
    *this = cpy;
}

Cat::~Cat()
{
	cout << "Cat destructor called" << endl;
}

Cat& Cat::operator = ( const Cat &obj )
{
    this->type = obj.type;
    return ( *this );
}

void Cat::makeSound( void ) const { cout << "Meeeooowww!" << endl; }

string Cat::getType( void ) const { return ( type ); }