/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:12:03 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:12:04 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN
#define BRAIN

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Brain
{
public:
    Brain();
    Brain( const Brain &cpy );

    Brain& operator = ( const Brain &obj );
    ~Brain();

private:
    string ideas[100];
};
#endif