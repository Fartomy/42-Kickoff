#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Fixed
{
public:
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
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

private:
	static const int	nbr;
	int					fx_nbr;
};

#endif