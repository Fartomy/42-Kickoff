#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap( string _name );
	ScavTrap( const ScavTrap &cpy );

	ScavTrap&	operator = ( const ScavTrap &obj );
	~ScavTrap();

	void	guardGate( void );
	void	attack( const string& target );

private:

};

#endif