#include "easyfind.hpp"

int main( void )
{
	try
	{
		std::vector<int> v;
		std::vector<int>::iterator itr;

		v.push_back(123);
		v.push_back(3);
		v.push_back(12);

		itr = easyfind( v, 3 );
		cout << *itr << endl;
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}
	try
	{
		std::vector<int> v2;
		std::vector<int>::iterator itr;

		v2.push_back(245);
		v2.push_back(655);
		v2.push_back(931);

		itr = easyfind( v2, 3 );
		cout << *itr << endl;
	}
	catch ( exception &e )
	{
		cerr << e.what() << endl;
	}

	return 0;
}