#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

using std::endl;
using std::cout;
using std::string;

class RobotomyRequestForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm( const RobotomyRequestForm &cpy );

	RobotomyRequestForm& operator = ( const RobotomyRequestForm &obj );
	~RobotomyRequestForm();

private:
};

#endif