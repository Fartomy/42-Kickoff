/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:27:36 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:27:37 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {};

Intern::~Intern() {};

const char *Intern::FormNotFound::what() const throw()
{
	return "Form not found!";
}

AForm *Intern::makeForm( string name, string target )
{
	AForm *form;
	int i = -1;
	string arr_name[3] = { "PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm" };
	AForm *createForm[3] = { new PresidentialPardonForm( target ), new RobotomyRequestForm( target ), new ShrubberyCreationForm( target ) };

	while ( ++i < 3 )
	{
		if( arr_name[i] == name )
			break;
	}
	switch ( i )
	{
		case 0 :
			cout << "Intern creates " << arr_name[0] << endl;
			form = createForm[0];
			delete createForm[1];
			delete createForm[2];
			break;
		case 1 :
			cout << "Intern creates " << arr_name[1] << endl;
			form = createForm[1];
			delete createForm[0];
			delete createForm[2];
			break;
		case 2 :
			cout << "Intern creates " << arr_name[2] << endl;
			form = createForm[2];
			delete createForm[1];
			delete createForm[0];
			break;
		default:
			for ( int j = 0; j < 3; ++j )
				delete createForm[j];
			throw FormNotFound();
	}
	return form;
}