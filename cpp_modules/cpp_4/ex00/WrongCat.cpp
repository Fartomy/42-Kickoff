/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:32 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:10:33 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    cout << "WrongCat default constructor called" << endl;
    type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &cpy ) : WrongAnimal()
{
    cout << "WrongCat copy constructor called" << endl;
    *this = cpy;
}

WrongCat::~WrongCat(){ cout << "WrongCat destructor called" << endl; }

WrongCat& WrongCat::operator = ( const WrongCat &obj )
{
    type = obj.type;
    return ( *this );
}

void WrongCat::makeSound( void ) const { cout << "Weeeeeeooooowwww!" << endl; }

string WrongCat::getType( void ) const { return ( type ); }