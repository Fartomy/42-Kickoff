#include "whatever.hpp"

template<typename T> void swap( T& a, T& b )
{
	T temp = a;

	a = b;
	b = temp;
}

template<typename T> T& min( T& a, T& b )
{
	if( a < b )
		return a;
	else if( b < a )
		return b;
	else
		return b;
}

template<typename T> T& max( T& a, T& b )
{
	if( a > b )
		return a;
	else if( b > a )
		return b;
	else
		return b;
}

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	cout << "a = " << a << ", b = " << b << endl;
	cout << "min( a, b ) = " << ::min( a, b ) << endl;
	cout << "max( a, b ) = " << ::max( a, b ) << endl;
	string c = "chaine1";
	string d = "chaine2";

	::swap(c, d);
	cout << "c = " << c << ", d = " << d << endl;
	cout << "min( c, d ) = " << ::min( c, d ) << endl;
	cout << "max( c, d ) = " << ::max( c, d ) << endl;

	return 0;
}