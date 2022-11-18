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
#include "Form.hpp"

int main( void )
{
	cout << "---------------ShrubberyCreationForm---------------" << endl;
	try
	{
		Bureaucrat br( "Rafet", 147 );
		Bureaucrat br2( "Sercan", 125 );
		Bureaucrat br3( "Sefa", 4 );

		ShrubberyCreationForm shForm( "ShrubberyForm" );

		br.signForm( shForm, br );
		br2.signForm( shForm, br2 );
		br3.signForm( shForm, br3 );

		br.executeForm( shForm );
		br2.executeForm( shForm );
		br3.executeForm( shForm );
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	cout << "---------------RobotomyRequestForm---------------" << endl;
	try
	{
		Bureaucrat br( "Ahmet", 34 );
		Bureaucrat br2( "Ercan", 145 );
		Bureaucrat br3( "Sedat", 14 );

		RobotomyRequestForm rbForm( "RobotoForm" );

		br.signForm( rbForm, br );
		br2.signForm( rbForm, br );
		br3.signForm( rbForm, br );

		br.executeForm( rbForm );
		br2.executeForm( rbForm );
		br3.executeForm( rbForm );
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	cout << "---------------PresidentialPardonForm---------------" << endl;
	try
	{
		Bureaucrat br( "Erdem", 34 );
		Bureaucrat br2( "Enes", 145 );
		Bureaucrat br3( "Kerem", 2 );

		PresidentialPardonForm prForm( "PresidentialForm" );

		br.signForm( prForm, br );
		br2.signForm( prForm, br2 );
		br3.signForm( prForm, br3 );

		br.executeForm( prForm );
		br2.executeForm( prForm );
		br3.executeForm( prForm );
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	return 0;
}