#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	setName( "" );
	setHealth( 100 );
	setEngPoint( 100 );
	setAtckDmg( 30 );
	cout << "FragTrap default constructor called" << endl;
};

FragTrap::FragTrap( string _name )
{
	setName( _name );
	setHealth( 100 );
	setEngPoint( 100 );
	setAtckDmg( 30 );
	cout << "FragTrap string constructor called" << endl;
};

FragTrap::FragTrap( const FragTrap &cpy )
{
	cout << "FragTrap copy constructor called" << endl;
	*this = cpy;
};

FragTrap::~FragTrap() { cout << "FragTrap destructor called" << endl; };

FragTrap&	FragTrap::operator = ( const FragTrap &obj )
{
	this->name = obj.name;
	this->atckDmg = obj.atckDmg;
	this->engPoint = obj.engPoint;
	this->health = obj.health;
	return ( *this );
}

void	FragTrap::highFivesGuys( void ) { cout << "HIGH FIVES GUYSSSSSSSSS!!! :)" << endl; }