#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		const Bureaucrat obj( "Furkan", 13 );
		const Bureaucrat obj2( "Ali", 167 );
	}
	catch (exception &e)
	{	
		cout << e.what() << endl;
	}

    return 0;
}