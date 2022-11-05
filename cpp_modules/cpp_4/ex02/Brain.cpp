#include "Brain.hpp"

Brain::Brain() { cout << "Brain default constructor called" << endl; }

Brain::Brain( const Brain &cpy )
{
    cout << "Brain copy constructor called" << endl;
    *this = cpy;
}

Brain& Brain::operator = ( const Brain &obj )
{
    ideas[100] = obj.ideas[100];
    return ( *this );
}

Brain::~Brain() { cout << "Brain destructor called" << endl; }