#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <time.h>

class Bureaucrat;

using std::endl;
using std::cout;
using std::string;

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm( string target );
	~RobotomyRequestForm();
	void execute( const Bureaucrat &obj );
	void exeAction( void );
};

#endif