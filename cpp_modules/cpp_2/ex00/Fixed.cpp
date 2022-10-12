#include "Fixed.hpp"

const int Fixed::nbr = 8;

int	Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (fx_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	fx_nbr = raw;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	cout << "Copy assigment operator called" << endl;
	this->fx_nbr = obj.getRawBits();
	return (*this);
}
