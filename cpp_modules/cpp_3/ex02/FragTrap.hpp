#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap( string _name );
	FragTrap( const FragTrap &cpy );

	FragTrap&	operator = ( const FragTrap &obj );
	~FragTrap();

	void	highFivesGuys( void );
};

#endif