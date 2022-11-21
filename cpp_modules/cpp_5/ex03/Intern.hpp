#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

using std::cout;
using std::endl;
using std::string;

class Intern
{
public:
	Intern();
	~Intern();

	struct FormNotFound : public exception
	{
		const char * what() const throw();
	};

	AForm* makeForm( string name, string target );
};

#endif