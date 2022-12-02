#include "easyfind.hpp"

int main( void )
{
	try
	{
		std::vector<int> v;

		v.push_back(123);
		v.push_back(3);
		v.push_back(12);

		std::vector<int>::iterator itr;
		itr = easyfind( v, 3 );
		cout << *itr << endl;
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}

	return 0;
}