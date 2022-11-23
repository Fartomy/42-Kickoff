/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:49 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:50 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( string target ) : AForm( target, 5, 25 ){};

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::execute( const Bureaucrat &obj ) const
{
	if ( getExecGrade() < obj.getGrade() )
		throw GradeTooLowException();
	if ( getIsSigned() == false )
		throw NotSignedException();
	exeAction( obj );
}

void PresidentialPardonForm::exeAction( const Bureaucrat &obj ) const
{
	( void )obj;
	cout << getName() << " Pardoned by Zaphod Beeblebrox. :d" << endl;
}