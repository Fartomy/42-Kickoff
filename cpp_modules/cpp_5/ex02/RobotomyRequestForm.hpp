#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::endl;
using std::cout;
using std::string;

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();

	void execute( const Bureaucrat &obj );
private:
};

#endif