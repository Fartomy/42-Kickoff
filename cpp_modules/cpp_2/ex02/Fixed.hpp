#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Fixed
{
public:
	Fixed();
	Fixed( const int _nbr );
	Fixed( const float _nbr );

	bool operator == ( const Fixed& obj1, const Fixed& obj2 );
	bool operator != ( const Fixed& obj1, const Fixed& obj2 );
	bool operator < ( const Fixed& obj1, const Fixed& obj2 );
	bool operator > ( const Fixed& obj1, const Fixed& obj2 );
	bool operator >= ( const Fixed& obj1, const Fixed& obj2 );
	bool operator <= ( const Fixed& obj1, const Fixed& obj2 );

	Fixed operator + ( Fixed const &obj );
	Fixed operator / ( Fixed const &obj );
	Fixed operator * ( Fixed const &obj );
	Fixed operator - ( Fixed const &obj );

	//add increment and decrement operator

	min( Fixed &obj, Fixed &obj2 );
	min( Fixed const &obj, Fixed const &obj2 );
	max( Fixed const &obj, Fixed const &obj2 );
	max( Fixed &obj, Fixed &obj2 );

private:
	int	fx_nbr;

};

#endif