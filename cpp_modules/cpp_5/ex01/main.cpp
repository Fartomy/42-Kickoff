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
		Bureaucrat obj( "Furkan", 13 );
		obj.incGrade();
		obj.incGrade();
		cout << "Name is " << obj.getName() << " Grade is " << obj.getGrade() << endl;
		obj.decGrade();
		cout << "Name is " << obj.getName() << " Grade is " << obj.getGrade() << endl;
		const Bureaucrat obj3( "Erdem", -5 );
	}
	catch ( exception &e )
	{	
		cout << e.what() << endl;
	}

    return 0;
}