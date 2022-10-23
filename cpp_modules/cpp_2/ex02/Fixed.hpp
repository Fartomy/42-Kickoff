#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Fixed
{
public:
	Fixed();
	Fixed( const int _nbr );
	Fixed( const float _nbr );
	
	~Fixed();

	bool operator == ( const Fixed& obj );
	bool operator != ( const Fixed& obj );
	bool operator < ( const Fixed& obj );
	bool operator > ( const Fixed& obj );
	bool operator >= ( const Fixed& obj );
	bool operator <= ( const Fixed& obj );

	Fixed operator + ( Fixed const &obj );
	Fixed operator / ( Fixed const &obj );
	Fixed operator * ( Fixed const &obj );
	Fixed operator - ( Fixed const &obj );

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	int		toInt( void ) const;
	float	toFloat( void ) const;

/* 	min( Fixed &obj, Fixed &obj2 );
	min( Fixed const &obj, Fixed const &obj2 );
	max( Fixed const &obj, Fixed const &obj2 );
	max( Fixed &obj, Fixed &obj2 ); */

	//Yukarida ki fonksiyonlar yazilmadi!

private:
	int	fx_nbr;

};

ostream& operator << ( ostream& out, const Fixed& obj );

#endif