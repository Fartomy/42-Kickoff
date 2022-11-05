#ifndef BRAIN
#define BRAIN

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Brain
{
public:
    Brain();
    Brain( const Brain &cpy );

    Brain& operator = ( const Brain &obj );
    ~Brain();

private:
    string ideas[100];
};
#endif