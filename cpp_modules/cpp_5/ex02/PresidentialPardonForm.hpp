#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

using std::endl;
using std::string;
using std::cout;

class PresidentialPardonForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm( const PresidentialPardonForm &cpy );

	PresidentialPardonForm& operator = ( const PresidentialPardonForm &obj );
	~PresidentialPardonForm();

private:
};


#endif
