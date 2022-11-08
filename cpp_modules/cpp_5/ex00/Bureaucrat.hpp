#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::exception;
using std::ostream;

class Bureaucrat
{
public:
	struct GradeTooHighException : public exception
	{
		const char* what() const throw();
	};
	struct GradeTooLowException : public exception
	{
		const char* what() const throw();
	};

    Bureaucrat( const string _name, int _grade );
    ~Bureaucrat();

    int getGrade( void ) const;
    string getName( void ) const;

	void incGrade( void );
	void decGrade( void );

private:
    const string name;
    int grade;
};

ostream& operator << ( ostream &ost, const Bureaucrat &obj );

#endif