/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:24:14 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::attack( const string &target )
{
	cout << "ClapTrap " << name << " attacks " << target << ", causing " << atckDmg << " points of damage!" << endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	health -= amount;
	cout << "ClapTrap deals " << amount << " damaged to " << name << endl;
}
̱
void	ClapTrap::beRepaired( unsigned int amount )
{
	engPoint -= amount;
	health += amount;
	cout << name << " repaired himself " << amount << endl;
}

string	ClapTrap::getName( void ) { return name; }

int		ClapTrap::getHealth( void ) { return health; }

int		ClapTrap::getEngpoint( void ) { return engPoint; }

int ClapTrap::getAtckDmg( void ) { return atckDmg; }

ClapTrap::ClapTrap() : health( 10 ), engPoint( 10 ), atckDmg( 0 ) { cout << "Default Constructor called" << endl; };

ClapTrap::ClapTrap( string _name ) : health( 10 ), engPoint( 10 ), atckDmg( 0 )
{
	cout << "String constructor called" << endl;
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
	cout << "Copy constructor called" << endl;
	*this = cpy;
};

ClapTrap::~ClapTrap() { cout << "Destructor called" << endl; };