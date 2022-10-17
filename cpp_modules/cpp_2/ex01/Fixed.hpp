#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using std::roundf;
using std::cout;
using std::endl;
using std::string;

class Fixed
{
public:
Fixed(const int nbr)
{

};

Fixed(const float nbr)
{

};
Fixed()
{
fx_nbr = 0;
cout << "Default constructor called" << endl;
};
Fixed(const Fixed& obj)
{
cout << "Copy constructor called" << endl;
fx_nbr = obj.getRawBits();
};
~Fixed()
{
cout << "Destructor called" << endl;
};
Fixed & operator = (const Fixed &obj);
float 		toFloat(void) const;
int 		toInt(void) const;
int			getRawBits(void) const;
void		setRawBits(int const raw);

private:
static const int	nbr;
int					fx_nbr;
};

#endif