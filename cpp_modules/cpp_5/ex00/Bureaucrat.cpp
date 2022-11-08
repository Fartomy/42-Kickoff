#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( string _name, int _grade ) : name( _name )
{
    if ( _grade > 150 )
        GradeTooHighException();
    else if ( _grade < 1 )
        GradeTooLowException();
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