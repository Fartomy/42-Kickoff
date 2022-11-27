#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate( void )
{
    int rnd = rand() % 3;

    switch ( rnd )
    {
        case 0 :
            return new A();
            break;
        case 1 :
            return new B();
            break;
        default:
            return new C();
            break;
    }
    return NULL;
}

void identify( Base* p )
{
    if ( ( A* )dynamic_cast<A*>( p ) != 0 )
        cout << "[ Identify Pointer Func ] - Identity Type is [ A ] " << endl;
    else if ( ( A* )dynamic_cast<B*>( p ) != 0 )
        cout << "[ Identify Pointer Func ] - Type is [ B ] " << endl;
    else
        cout << "[ Identify Pointer Func ] - Type is [ C ]" << endl;
    
}

void identify( Base& p )
{

}