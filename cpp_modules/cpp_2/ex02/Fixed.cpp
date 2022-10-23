#include "Fixed.hpp"

Fixed::Fixed() : fx_nbr(0)
{
	cout << "Default constructor called" << endl;
};

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
};

Fixed::Fixed(const int _nbr)
{
	cout << "Int constructor called" << endl;
	fx_nbr = _nbr * 256;
};

Fixed::Fixed(const float _nbr)
{
	cout << "Float constructor called" << endl;
	fx_nbr = _nbr * 256;
};

bool	Fixed::operator == ( const Fixed &obj )
{
	return ( this->fx_nbr == obj.fx_nbr );
}

bool	Fixed::operator != ( const Fixed &obj )
{
	return ( this->fx_nbr != obj.fx_nbr );
}

bool	Fixed::operator > ( const Fixed &obj )
{
	return ( this->fx_nbr > obj.fx_nbr );
}

bool	Fixed::operator < ( const Fixed &obj )
{
	return ( this->fx_nbr < obj.fx_nbr );
}

bool	Fixed::operator >= ( const Fixed &obj )
{
	return ( this->fx_nbr >= obj.fx_nbr );
}

bool	Fixed::operator <= ( const Fixed &obj )
{
	return ( this->fx_nbr <= obj.fx_nbr );
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

float	Fixed::toFloat( void ) const
{
	return ( fx_nbr / 256.0f);
}

int		Fixed::toInt( void ) const
{
	return ( fx_nbr / 256 );
}

ostream& operator << ( ostream& out, const Fixed& obj )
{
	out << obj.toFloat();
	return ( out );
}