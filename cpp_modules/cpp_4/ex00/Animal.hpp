/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:09:55 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:09:56 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Animal
{
public:
	Animal();
	Animal( const Animal& cpy );

	virtual ~Animal();
	Animal& operator = (const Animal &obj);

	virtual void makeSound( void ) const;
	virtual string getType( void ) const;

protected:
	string type;
};


#endif