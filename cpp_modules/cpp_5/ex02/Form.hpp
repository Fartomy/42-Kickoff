#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::cout;
using std::string;
using std::endl;
using std::exception;
using std::ostream;

class Form
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

    Form( string _name, int _exec, int _signed );
    ~Form();

    string getName( void ) const;
    int getSignGrade( void ) const;
    int getExecGrade( void ) const;
    bool getIsSigned( void ) const;

    void beSigned( const Bureaucrat &obj );

private:
    const string name;
    const int sign_grade;
    const int exec_grade;
    bool is_signed;
};

ostream& operator << ( ostream &ost, const Form &form );

#endif