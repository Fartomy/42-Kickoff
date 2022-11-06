#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Bureaucrat
{
public:    
    Bureaucrat( const string _name, int _grade );
    ~Bureaucrat();

    int getGrade( void );
    string getName( void ) const;

private:
    const string name;
    int grade;
};


#endif