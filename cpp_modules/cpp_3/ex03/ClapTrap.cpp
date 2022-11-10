/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:24:51 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:43 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::attack( const string &target )
{
	cout << "ClapTrap " << name << " attacks " << target << ", causing " << atckDmg << " points of damage!" << endl;
	cout << "Losed 1 energy point! " << endl;
	this->takeDamage( atckDmg );
	engPoint -= 1;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	health -= amount;
	cout << "ClapTrap deals " << amount << " damaged to " << name << endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	engPoint -= 1;
	health += amount;
	cout << name << " repaired himself " << amount << endl;
	cout << "Losed 1 energy point! " << endl;
}

string	ClapTrap::getName( void ) { return name; }

int		ClapTrap::getHealth( void ) { return health; }

int		ClapTrap::getEngpoint( void ) { return engPoint; }

int		ClapTrap::getAtckDmg( void ) { return atckDmg; }

void	ClapTrap::setName( string _name ) { name = _name; }

void	ClapTrap::setHealth( int _health ) { health = _health; }

void	ClapTrap::setEngPoint( int _engPoint ) { engPoint = _engPoint; }

void	ClapTrap::setAtckDmg( int _atckDmg ) { atckDmg = _atckDmg; }

ClapTrap::ClapTrap() : name(""), health( 10 ), engPoint( 10 ), atckDmg( 0 ) { cout << "ClapTrap default constructor called" << endl; };

ClapTrap::ClapTrap( string _name ) : name(""), health( 10 ), engPoint( 10 ), atckDmg( 0 )
{
	cout << "ClapTrap string constructor called" << endl;
	name = _name;
};

ClapTrap&	ClapTrap::operator = ( const ClapTrap &cpy )
{
	name = cpy.name;
	engPoint = cpy.engPoint;
	health = cpy.health;
	atckDmg = cpy.atckDmg;
	return ( *this );
}

ClapTrap::ClapTrap( const ClapTrap &cpy )
{
	cout << "ClapTrap copy constructor called" << endl;
	*this = cpy;
};

ClapTrap::~ClapTrap() { cout << "ClapTrap destructor called" << endl; };