/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:12:18 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:12:19 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog( const Dog &cpy );

	Dog& operator = ( const Dog &obj );
	~Dog();

	void makeSound( void ) const;
	string getType( void ) const;

private:
	Brain *dogBrn;
};

#endif