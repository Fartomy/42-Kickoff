#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;
using std::cout;
using std::endl;
using std::string;

class Intern
{
public:
	Intern();
	~Intern();

	Form* makeForm( string name, string target );
};

#endif