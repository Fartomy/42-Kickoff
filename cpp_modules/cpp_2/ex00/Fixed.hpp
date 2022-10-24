/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:36:09 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/24 13:38:36 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Fixed( const Fixed& cpy );
	~Fixed();
	
	Fixed& operator = ( const Fixed &asg );
	
	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

private:
	static const int	nbr;
	int					fx_nbr;
};

#endif