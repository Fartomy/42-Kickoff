/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:12:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:12:39 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &cpy);

    WrongAnimal& operator = ( const WrongAnimal &obj );
    ~WrongAnimal();

    void makeSound( void ) const;
    string  getType( void ) const;

protected:
    string type;
};

#endif