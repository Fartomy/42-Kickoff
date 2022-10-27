#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap( const DiamondTrap &cpy );
	DiamondTrap( string _name );

	DiamondTrap&	operator = ( const DiamondTrap &obj );
	~DiamondTrap();

	string	getName( void );
	void	whoAmI( void );

private:
	string name;
};

#endif