#include "TypeCast.hpp"

int main( int ac, char **av )
{
	if ( ac == 2 )
	{
		try
		{
			TypeCast obj;
			obj.display( which_type( av[1] ), av[1] );
		}
		catch ( exception &e )
		{
			cerr << "Program have a problem, because: " << e.what() << endl;
		}
	}
	else
		cout << "Wrong arguments!" << endl;
}