#include "Fixed.hpp"

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
};

Fixed::Fixed(const int _nbr)
{
	cout << "Int constructor called" << endl;
	fx_nbr = _nbr
};

Fixed::Fixed(const float _nbr)
{
	cout << "Float constructor called" << endl;
	fx_nbr = _nbr;
};

bool	Fixed::operator == ( const Fixed &obj1, const Fixed &obj2 )
{
	return ( obj1.fx_nbr == obj2.fx_nbr );
}

bool	Fixed::operator != ( const Fixed &obj1, const Fixed &obj2 )
{
	return ( obj1.fx_nbr != obj2.fx_nbr );
}

bool	Fixed::operator > ( const Fixed &obj1, const Fixed &obj2 )
{
	return ( obj1.fx_nbr > obj2.fx_nbr );
}

bool	Fixed::operator < ( const Fixed &obj1, const Fixed &obj2 )
{
	return ( obj1.fx_nbr < obj2.fx_nbr );
}

bool	Fixed::operator >= ( const Fixed &obj1, const Fixed &obj2 )
{
	return ( obj1.fx_nbr >= obj2.fx_nbr );
}

bool	Fixed::operator <= ( const Fixed &obj1, const Fixed &obj2 )
{
	return ( obj1.fx_nbr <= obj2.fx_nbr );
}

Fixed	Fixed::operator + ( const Fixed &obj )
{
	Fixed new_obj;

	new_obj.fx_nbr = fx_nbr + obj.fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator - ( const Fixed &obj )
{
	Fixed new_obj;

	new_obj.fx_nbr = fx_nbr - obj.fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator * ( const Fixed &obj )
{
	Fixed new_obj;

	new_obj.fx_nbr = fx_nbr * obj.fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator / ( const Fixed &obj )
{
	Fixed new_obj;

	new_obj.fx_nbr = fx_nbr / obj.fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator ++ ( void )
{
	Fixed new_obj;

	new_obj.fx_nbr = ++fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator ++ (int)
{
	Fixed new_obj;

	new_obj.fx_nbr = fx_nbr++;
	return (new_obj);
}