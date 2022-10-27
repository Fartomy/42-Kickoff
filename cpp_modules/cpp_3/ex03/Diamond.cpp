#include "Diamond.hpp"

DiamondTrap::DiamondTrap()
{
	cout << "Diamond default constructor called" << endl;
	name = "";
	ClapTrap::setName( "" );
	FragTrap::setHealth( FragTrap::health ); // olmazsa --> bunu dene FragTrap::getHealth() o da olmazsa --> direkt sayisal deger
	FragTrap::setAtckDmg( FragTrap::atckDmg );
	ScavTrap::setEngPoint( ScavTrap::engPoint );
};

DiamondTrap::DiamondTrap( string _name )
{
	cout << "Diamond string constructor called" << endl;
	name = _name;
	ClapTrap::setName( _name + "_clap_name" );
	FragTrap::setHealth( FragTrap::health );
	FragTrap::setAtckDmg( FragTrap::atckDmg );
	ScavTrap::setEngPoint( ScavTrap::engPoint );
};

DiamondTrap::DiamondTrap( const DiamondTrap &cpy )
{
	cout << "Copy constructor called" << endl;
	*this = cpy;
};

DiamondTrap::~DiamondTrap() { cout << "Diamond destructor called" << endl; };

DiamondTrap&	DiamondTrap::operator = ( const DiamondTrap &obj )
{
	this->name = obj.name;
	this->engPoint = obj.engPoint;
	this->atckDmg = obj.atckDmg;
	this->health = obj.health;
	return ( *this );
}

void	DiamondTrap::whoAmI( void ) { cout << name << ClapTrap::name << endl; }

string	DiamondTrap::getName( void ) { return name; }