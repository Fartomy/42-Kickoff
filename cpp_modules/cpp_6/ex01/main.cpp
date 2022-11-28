#include "Data.hpp"

int main( void )
{
	Data dt;
	Data* dtPtr = &dt;

	cout << deserialize( serialize( dtPtr ) )->a << endl;
	cout << deserialize( serialize( dtPtr ) )->ch << endl;
	cout << deserialize( serialize( dtPtr ) )->b << endl;

	return 0;
}