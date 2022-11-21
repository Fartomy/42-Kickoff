#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::cout;
using std::string;
using std::endl;
using std::exception;
using std::ostream;

class AForm
{
public:
    struct GradeTooHighException : public exception
    {
        const char * what() const throw();
    };
    struct GradeTooLowException : public exception
    {
        const char * what() const throw();
    };
	struct NotSignedException : public exception
	{
		const char * what() const throw();
	};

    AForm( string _name, int _exec, int _signed );
    virtual ~AForm();

    string getName( void ) const;
    int getSignGrade( void ) const;
    int getExecGrade( void ) const;
    bool getIsSigned( void ) const;

    void beSigned( const Bureaucrat &obj );

	virtual void execute( Bureaucrat const &obj ) const = 0;
	virtual void exeAction( const Bureaucrat &obj ) const;

private:
    const string name;
    const int sign_grade;
    const int exec_grade;
    bool is_signed;
};

ostream& operator << ( ostream &ost, const AForm &form );

#endif