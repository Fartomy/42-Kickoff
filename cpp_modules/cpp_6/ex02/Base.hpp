/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:26:13 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/30 17:26:14 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::bad_cast;

class Base
{
public:
    Base();
    virtual ~Base();
};

Base* generate( void );
void identify( Base* p );
void identify( Base& p );

#endif