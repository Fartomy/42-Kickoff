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

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main( void )
{
	cout << "------------------------TRY SUCCESS TEST------------------------" << endl;
	try
	{
		Intern anyIntern;
		Bureaucrat brc1( "Kazim", 134 );
		Bureaucrat brc2( "Busra", 2 );
		Bureaucrat brc3( "Sevil", 56 );
		AForm *frm;

		frm = anyIntern.makeForm( "ShrubberyCreationForm", "Mehmet" );
		brc1.signForm( *frm, brc1 );
		brc2.signForm( *frm, brc2 );
		brc3.signForm( *frm, brc3 );
		brc1.executeForm( *frm );
		brc2.executeForm( *frm );
		brc3.executeForm( *frm );

		delete frm;
	}
	catch ( exception &e)
	{
		cout << "Form have a exception, exception is: " << e.what() << endl;
	}
	cout << "------------------------TRY FAIL TEST------------------------" << endl;
	try
	{
		Intern anotherIntern;
		Bureaucrat brc1( "Tugalp", 121 );
		Bureaucrat brc2( "Sinan", 21 );
		Bureaucrat brc3( "Rafet", 73 );
		AForm *frm;

		frm = anotherIntern.makeForm("xdxdxdxdForm", "Erdinc");

		brc1.signForm( *frm, brc1 );
		brc2.signForm( *frm, brc2);
		brc3.signForm( *frm, brc3 );
		brc1.executeForm( *frm );
		brc2.executeForm( *frm );
		brc3.executeForm( *frm );

		delete frm;
	}
	catch ( exception &e )
	{
		cout << "Form have a exception, exception is: " << e.what() << endl;
	}
	return 0;
}