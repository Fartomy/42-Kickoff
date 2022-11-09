/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:11:54 by ftekdrmi         ###   ########.fr       */
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

	virtual void makeSound( void ) const = 0;
	virtual string getType( void ) const;

protected:
	string type;
};


#endif