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
	Fixed(const int nbr);
	Fixed(const float _fx_nbr);
	Fixed(const Fixed &obj);

	~Fixed();

	Fixed &operator=(const Fixed &obj);

	int		getRawBits(void) const;
	int		toInt(void) const;
	float	toFloat( void ) const;
	void	setRawBits(int const raw);

private:

	static const int	nbr;
	int 				fx_nbr;
};