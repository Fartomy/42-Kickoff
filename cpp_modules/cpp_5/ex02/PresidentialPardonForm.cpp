#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( string target ) : Form( target, 5, 25 ){};

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