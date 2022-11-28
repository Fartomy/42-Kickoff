#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::bad_cast;

class Base
{
public:
    Base();
    virtual ~Base();
};

Base* generate( void );
void identify( Base* p );
void identify( Base& p );

#endif