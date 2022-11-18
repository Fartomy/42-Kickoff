#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <time.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::endl;
using std::cout;
using std::string;

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm( string target );
	~RobotomyRequestForm();
	void execute( const Bureaucrat &obj ) const;
	void exeAction( const Bureaucrat &obj ) const;
};

#endif