/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:25:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/30 17:26:09 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Data
{
public:
    Data();
    Data( const Data &cpy );
    Data& operator = ( const Data& obj );
    ~Data();
	int a;
	char ch;
	bool b;
};

uintptr_t serialize( Data* ptr );
Data* deserialize( uintptr_t raw );

#endif
