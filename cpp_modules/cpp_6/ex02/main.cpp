#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main( void )
{
	Base* bp = generate();

	identify( bp );
	identify( *bp );

	delete bp;

	return 0;
}