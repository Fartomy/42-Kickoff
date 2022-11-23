/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:27 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:28 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( string _name, int _signed, int _exec ) : name( _name ),  sign_grade( _signed ), exec_grade( _exec )
{
    if ( _exec > 150 || _signed > 150 )
        throw GradeTooHighException();
    if ( _exec < 1 || _signed < 1)
        throw GradeTooLowException();
	cout << "Form Created, It Name is: " << name << endl;
};

Form::~Form()
{
    cout << "Destroyed Form" << endl;
};

const char * Form::GradeTooHighException::what() const throw()
{
    return ( "It's too high grade!" );
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ( "It's too low grade!" );
}

string Form::getName( void ) const { return ( name ); }

int Form::getExecGrade( void ) const { return ( exec_grade ); }

int Form::getSignGrade( void ) const { return ( sign_grade ); }

bool Form::getIsSigned( void ) const { return ( is_signed ); }

void Form::beSigned( const Bureaucrat &brc )
{
    if ( getSignGrade() < brc.getGrade() )
        throw GradeTooLowException();
    else
        is_signed = true;
}

ostream& operator << ( ostream &ost, const Form &form )
{
    ost << endl << "Form Informations: " << form.getName() << endl << form.getIsSigned() << endl << form.getExecGrade() << endl << form.getSignGrade() << endl;
    return ( ost );
}