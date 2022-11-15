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
#include "Form.hpp"

int main( void )
{
	try
	{	// We are trying brc grade bigger than frm sign grade. We will get an error. Because brc grade bigger than frm grade. Form's grade not enough of Tuncay's grade.
		Bureaucrat brc( "Tuncay", 60 );
		Form frm( "Test", 33, 123 );

		cout << frm << endl;
		brc.signForm( frm, brc );
	}
	catch ( exception &e )
	{	
		cerr << e.what() << endl;
	}
	cout << "/-----------------------------------------------------------------------/" << endl;
	try
	{
		Bureaucrat brc2( "Ercan", 23 );
		Form frm2( "Test-2", 45, 121);

		cout << frm2 << endl;
		brc2.signForm( frm2, brc2 );
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	cout << "/-----------------------------------------------------------------------/" << endl;
	try
	{
		Form frm3( "Test-3", 156, 2 );
	}
	catch (exception &e)
	{
		cerr << e.what() << endl;
	}
	cout << "/-----------------------------------------------------------------------/" << endl;
	try
	{
		Form frm4( "Test-4", 54, 234234 );
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	cout << "/-----------------------------------------------------------------------/" << endl;
	try
	{
		Form frm5( "Test-5", -52, 24 );
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	cout << "/-----------------------------------------------------------------------/" << endl;
	try
	{
		Form frm5( "Test-6", 125, -123 );
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	return 0;
}