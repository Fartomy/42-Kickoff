#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( string target ) : Form( target, 5, 25 ){};

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::execute( const Bureaucrat &obj )
{
	if ( getExecGrade() < obj.getGrade() )
		throw GradeTooLowException();
	if ( getIsSigned() == false )
		throw NotSignedException();
	exeAction();
}

void PresidentialPardonForm::exeAction( void )
{
	cout << getName() << " Pardoned by Zaphod Beeblebrox. :d" << endl;
}