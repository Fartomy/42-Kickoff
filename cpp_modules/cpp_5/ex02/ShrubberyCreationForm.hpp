#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>

using std::endl;
using std::string;
using std::cout;

class ShrubberyCreationForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( const ShrubberyCreationForm &cpy );

	ShrubberyCreationForm& operator = ( const ShrubberyCreationForm &obj );
	~ShrubberyCreationForm();

private:
};

#endif