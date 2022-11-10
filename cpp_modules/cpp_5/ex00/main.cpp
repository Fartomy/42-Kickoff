/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:13:07 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:13:08 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		const Bureaucrat obj( "Furkan", 13 );
		const Bureaucrat obj3( "Erdem", -5 );
		const Bureaucrat obj2( "Ali", 167 );
	}
	catch ( exception &e )
	{	
		cout << e.what() << endl;
	}

    return 0;
}