#include "Fixed.hpp"

const int Fixed::nbr = 8;

Fixed::Fixed()
{
	fx_nbr = 0;
	cout << "Default constructor called" << endl;
};

Fixed::Fixed(const Fixed& obj)
{
	cout << "Copy constructor called" << endl;
	fx_nbr = obj.getRawBits();
};

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
};

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (fx_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	fx_nbr = raw;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	cout << "Copy assigment operator called" << endl;
	this->fx_nbr = obj.getRawBits();
	return (*this);
}
