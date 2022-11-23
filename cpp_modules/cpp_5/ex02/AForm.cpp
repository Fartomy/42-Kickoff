/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:35 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:36 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( string _name, int _signed, int _exec ) : name( _name ),  sign_grade( _signed ), exec_grade( _exec )
{
    if ( _exec > 150 || _signed > 150 )
        throw GradeTooHighException();
    if ( _exec < 1 || _signed < 1)
        throw GradeTooLowException();
	cout << "Form Created, It Name is: " << name << endl;
};

AForm::~AForm() { cout << "Destroyed Form" << endl; };

const char * AForm::GradeTooHighException::what() const throw()
{
    return ( "It's too high grade!" );
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return ( "It's too low grade!" );
}

const char * AForm::NotSignedException::what() const throw()
{
	return ( "Form is not signed!" );
}

string AForm::getName( void ) const { return ( name ); }

int AForm::getExecGrade( void ) const { return ( exec_grade ); }

int AForm::getSignGrade( void ) const { return ( sign_grade ); }

bool AForm::getIsSigned( void ) const { return ( is_signed ); }

void AForm::beSigned( const Bureaucrat &brc )
{
    if ( getSignGrade() < brc.getGrade() )
        throw GradeTooLowException();
    else
        is_signed = true;
}

ostream& operator << ( ostream &ost, const AForm &form )
{
    ost << endl << "Form Informations: " << form.getName() << endl << form.getIsSigned() << endl << form.getExecGrade() << endl << form.getSignGrade() << endl;
    return ( ost );
}

void AForm::execute( const Bureaucrat &obj ) const
{
	if ( getExecGrade() < obj.getGrade() )
		throw GradeTooLowException();
	if ( getIsSigned() == false )
		throw NotSignedException();
	exeAction( obj );
}

void AForm::exeAction( const Bureaucrat &obj ) const
{
	cout << obj.getName() << " executed " << getName() << endl;
}