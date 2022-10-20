/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:36:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/19 13:36:32 by ftekdrmi         ###   ########.fr       */
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
	Fixed( const int _fx_nbr );
	Fixed( const float _fx_nbr );
	Fixed( const Fixed &obj );

	~Fixed();

	Fixed& operator = ( const Fixed &obj );
	ostream& operator << ( ostream& out, const Fixed& obj );

	int		getRawBits( void ) const;
	int		toInt( void ) const;
	float	toFloat( void ) const;
	void	setRawBits( int const raw );

private:

	static const int	nbr;
	int 				fx_nbr;
};

#endif