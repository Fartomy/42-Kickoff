#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( string target ) : Form(target, 45, 72) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

void RobotomyRequestForm::execute( const Bureaucrat &obj ) const
{
	if ( getExecGrade() < obj.getGrade() )
		throw GradeTooLowException();
	if( getIsSigned() == false )
		throw NotSignedException();
	exeAction( obj );
}

void RobotomyRequestForm::exeAction( const Bureaucrat &obj ) const
{
	( void )obj;
	int tmp;

	srand( time( NULL ) );
	tmp = rand() % 100;
	if ( tmp < 50 )
		cout << getName() << " is succesfully robotomized" << endl;
	else
		cout << getName() << " is not robotomized" << endl;
}