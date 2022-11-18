#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::endl;
using std::string;
using std::cout;

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();

	void execute( const Bureaucrat &obj );
private:
};


#endif
