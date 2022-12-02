#include "Span.hpp"

int main( void )
{
	try
	{
		Span sp = Span( 5 );

		sp.addNumber( 6 );
		sp.addNumber( 3 );
		sp.addNumber( 17 );
		sp.addNumber( 9 );
		sp.addNumber( 11 );

		cout << sp.shortestSpan() << endl;
		cout << sp.longestSpan() << endl;
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	cout << "--------------------------------------------" << endl;
	try
	{
		Span sp = Span(3);

		sp.addNumber( 235 );
		sp.addNumber( 255 );
		sp.addNumber( 23 );
		sp.addNumber( 456 );
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	cout << "--------------------------------------------" << endl;
	try
	{
		Span sp = Span( 1 );
		sp.addNumber(923);

		cout << sp.shortestSpan() << endl;
		cout << sp.longestSpan() << endl;
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	cout << "--------------------------------------------" << endl;
	try
	{
		Span sp = Span( 10000 );

		for (int i = 0; i < 10000; ++i)
			sp.addNumber( i );
		cout << sp.shortestSpan() << endl;
		cout << sp.longestSpan() << endl;
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}

	return 0;
}