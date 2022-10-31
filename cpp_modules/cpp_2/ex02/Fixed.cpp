/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:35:13 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:50:59 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fx_nbr( 0 ) { cout << "Default constructor called" << endl; };

Fixed::~Fixed() { cout << "Destructor called" << endl; };

Fixed::Fixed( const int _nbr )
{
	cout << "Int constructor called" << endl;
	fx_nbr = _nbr * 256;
};

Fixed::Fixed( const float _nbr )
{
	cout << "Float constructor called" << endl;
	fx_nbr = ( int )roundf( _nbr * 256 );
};

bool	Fixed::operator == ( const Fixed &obj ) { return ( this->fx_nbr == obj.fx_nbr ); }

bool	Fixed::operator != ( const Fixed &obj ) { return ( this->fx_nbr != obj.fx_nbr ); }

bool	Fixed::operator > ( const Fixed &obj ) { return ( this->fx_nbr > obj.fx_nbr ); }

bool	Fixed::operator < ( const Fixed &obj ) { return ( this->fx_nbr < obj.fx_nbr ); }

bool	Fixed::operator >= ( const Fixed &obj ) { return ( this->fx_nbr >= obj.fx_nbr ); }

bool	Fixed::operator <= ( const Fixed &obj ) { return ( this->fx_nbr <= obj.fx_nbr ); }

Fixed	Fixed::operator + ( const Fixed &obj )
{
	Fixed new_obj;

	new_obj.fx_nbr = this->toFloat() + obj.fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator - ( const Fixed &obj )
{
	Fixed new_obj;

	new_obj.fx_nbr = this->toFloat() - obj.fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator * ( const Fixed &obj )
{
	Fixed new_obj;

	new_obj.fx_nbr = this->toFloat() * obj.fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator / ( const Fixed &obj )
{
	Fixed new_obj;

	new_obj.fx_nbr = this->toFloat() / obj.fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator ++ ( void )
{
	Fixed new_obj;

	new_obj.fx_nbr = ++fx_nbr;
	return new_obj;
}

Fixed	Fixed::operator ++ ( int )
{
	Fixed new_obj;

	new_obj.fx_nbr = fx_nbr++;
	return (new_obj);
}

Fixed const&	Fixed::max( Fixed const &obj1, Fixed const &obj2 )
{
	if ( obj1.toFloat() > obj2.toFloat() )
		return ( obj1 );
	return ( obj2 );
}

Fixed&	Fixed::max( Fixed& obj1, Fixed& obj2 )
{
	if ( obj1.toFloat() > obj2.toFloat() )
		return ( obj1 );
	return ( obj2 );
	
}

Fixed const&	Fixed::min( Fixed const &obj1, Fixed const &obj2 )
{
	if( obj1.toFloat() < obj2.toFloat() )
		return ( obj1 );
	return ( obj2 );
}

Fixed&	Fixed::min( Fixed& obj1, Fixed& obj2 )
{
	if ( obj1.toFloat() < obj2.toFloat() )
		return ( obj1 );
	return ( obj2 );
	
}

float	Fixed::toFloat( void ) const { return ( ( float )fx_nbr / 256); }

int		Fixed::toInt( void ) const { return ( fx_nbr / 256 ); }

Fixed&	Fixed::operator = ( const Fixed &obj )
{
	cout << "Copy assigment operator called" << endl;
	fx_nbr = obj.fx_nbr;
	return ( *this );
}

Fixed::Fixed( const Fixed& cpy )
{
	cout << "Copy constructor called" << endl;
	fx_nbr = cpy.getRawBits();
};

ostream& operator << ( ostream& out, const Fixed& obj )
{
	out << obj.toFloat();
	return ( out );
}

int		Fixed::getRawBits( void ) const { return ( fx_nbr ); }