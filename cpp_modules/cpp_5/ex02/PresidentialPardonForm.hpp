#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::string;
using std::endl;
using std::cout;

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm( string target );
	~PresidentialPardonForm();

	void execute( const Bureaucrat &obj ) const;
	void exeAction( const Bureaucrat &obj ) const;
private:
};


#endif
