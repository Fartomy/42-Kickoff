#include "iter.hpp"

template<typename T> void display( T const& a )
{
	cout << a << endl;
}

int main( void )
{
	int a[] = { 1, 2, 3, 4, 5 };
	char c[] = { 'a', 'b', 'c', 'd', 'e' };

	cout << "----*INT*----" << endl;
	iter(a, 5, display );
	cout << "----*CHAR*----" << endl;
	iter( c, 5, display );;

	return 0;
}
