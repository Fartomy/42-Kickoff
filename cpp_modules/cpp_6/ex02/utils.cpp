#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate( void )
{
	srand( time( NULL ) );
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
    if ( ( A* )dynamic_cast<A*>( p ) != nullptr )
        cout << "[ Identify Pointer Func ] - Type is [ A ] " << endl;
    else if ( ( B* )dynamic_cast<B*>( p ) != nullptr )
        cout << "[ Identify Pointer Func ] - Type is [ B ] " << endl;
    else if ( ( C* )dynamic_cast<C*>( p ) != nullptr )
        cout << "[ Identify Pointer Func ] - Type is [ C ]" << endl;
}

void identify( Base& p )
{
	try
	{
		Base& bRf = dynamic_cast<A&>( p );
		( void )bRf;
		cout << "[ Identify Reference Func ] - Type is [ A ]" << endl;
	}
	catch ( bad_cast ){}
	try
	{
		Base& bRf = dynamic_cast<B&>( p );
		( void )bRf;
		cout << "[ Identify Reference Func ] - Type is [ B ]" << endl;
	}
	catch ( bad_cast ){}
	try
	{
		Base& bRf = dynamic_cast<C&>( p );
		( void )bRf;
		cout << "[ Identify Reference Func ] - Type is [ C ]" << endl;
	}
	catch ( bad_cast ){}
}