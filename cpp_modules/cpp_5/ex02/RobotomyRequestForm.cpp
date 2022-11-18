#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( string target ) : Form(target, 45, 72) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

void RobotomyRequestForm::execute( const Bureaucrat &obj )
{
	if ( getExecGrade() < obj.getGrade() )
		throw GradeTooLowException();
	if( getIsSigned() == false )
		throw NotSignedException();
	exeAction();
}

void RobotomyRequestForm::exeAction( void )
{
	int tmp;

	srand( time( NULL ) );
	tmp = rand() % 100;
	if ( tmp < 50 )
		cout << getName() << " is succesfully robotomized" << endl;
	else
		cout << getName() << " is not robotomized" << endl;
}