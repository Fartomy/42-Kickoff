/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:35:16 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/24 13:47:23 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Fixed( const Fixed &cpy );

	Fixed&	operator = ( const Fixed &obj );
	
	~Fixed();

	bool	operator == ( const Fixed& obj );
	bool	operator != ( const Fixed& obj );
	bool	operator < ( const Fixed& obj );
	bool	operator > ( const Fixed& obj );
	bool	operator >= ( const Fixed& obj );
	bool	operator <= ( const Fixed& obj );

	Fixed	operator + ( Fixed const &obj );
	Fixed	operator / ( Fixed const &obj );
	Fixed	operator * ( Fixed const &obj );
	Fixed	operator - ( Fixed const &obj );

	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	int		toInt( void ) const;
	float	toFloat( void ) const;

	static	Fixed& min( Fixed& obj1, Fixed& obj2 );
	static	Fixed const &min( Fixed const &obj1, Fixed const &obj2 );
	static	Fixed const &max( Fixed const &obj1, Fixed const &obj2 );
	static	Fixed& max( Fixed& obj1, Fixed& obj2 );

private:
	int	fx_nbr;

};

ostream&	operator << ( ostream& out, const Fixed& obj );

#endif