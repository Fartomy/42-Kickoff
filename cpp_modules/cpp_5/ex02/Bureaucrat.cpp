/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:13:01 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:13:02 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( string _name, int _grade ) : name( _name )
{
    if ( _grade > 150 )
        throw ( GradeTooHighException() );
    else if ( _grade < 1 )
		throw ( GradeTooLowException() );
    grade = _grade;
    cout << name << " Created," << " " << "Grade is: " << grade << endl;;
}

Bureaucrat::~Bureaucrat() { cout << name << " Destructor called" << endl; }

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ( "Too High Grade!!" );
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( "Too Low Grade!!" );
}

int Bureaucrat::getGrade( void ) const { return ( grade ); }

string Bureaucrat::getName( void ) const { return ( name ); }

void Bureaucrat::decGrade( void )
{
    if ( grade - 1 < 1 )
        throw ( GradeTooLowException() );
    else
        grade--;
}

void Bureaucrat::incGrade( void )
{
    if ( grade + 1 > 150 )
        throw ( GradeTooHighException() );
    else
        grade++;
}

ostream& operator << ( ostream &ost, const Bureaucrat &obj )
{
	ost << obj.getName() << " bureaucrat grade " << obj.getGrade();
	return ( ost );
}


void Bureaucrat::signForm( Form &form, Bureaucrat &brc )
{
    try
    {
        form.beSigned( brc );
        cout << name << " signed " << form.getName() << endl;
    }
    catch( exception &e )
    {
        cerr << name << " couldn't " << form.getName() << " because " << e.what() << endl;
    }
}

void Bureaucrat::executeForm( Form const &form )
{
	try
	{
		form.execute( *this );
	}
	catch ( exception &e )
	{
		cerr << getName() << " cannot executed " << form.getName() << " reason is: " << e.what() << endl;
	}
}