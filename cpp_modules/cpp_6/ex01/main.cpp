/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:25:56 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/30 17:26:09 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main( void )
{
	Data dt;
	Data* dtPtr = &dt;

	cout << deserialize( serialize( dtPtr ) )->a << endl;
	cout << deserialize( serialize( dtPtr ) )->ch << endl;
	cout << deserialize( serialize( dtPtr ) )->b << endl;

	return 0;
}