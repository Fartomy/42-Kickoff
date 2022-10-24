#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(string _name);
	ClapTrap( const ClapTrap &cpy );

	ClapTrap&	operator = ( const ClapTrap &obj );
	~ClapTrap();

	string	getName( void );
	int		getHealth( void );
	int 	getEngpoint( void );
	int		getAtckDmg( void );

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	string	name;
	int		health;
	int		engPoint;
	int 	atckDmg;
};

#endif