#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::endl;
using std::string;
using std::cout;
using std::ofstream;

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( string target );
	~ShrubberyCreationForm();
	void execute( const Bureaucrat &obj ) const;
	void exeAction( const Bureaucrat &obj ) const;
};

#endif