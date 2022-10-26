/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:24:54 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:23 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ClapTrap( string _name );
	ClapTrap( const ClapTrap &cpy );

	ClapTrap&	operator = ( const ClapTrap &obj );
	~ClapTrap();

	string	getName( void );
	int		getHealth( void );
	int 	getEngpoint( void );
	int		getAtckDmg( void );

	void	setName( string _name );
	void	setHealth( int _health );
	void	setEngPoint( int _engPoint );
	void	setAtckDmg( int _atckDmg );

	void	attack( const string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

protected:
	string	name;
	int		health;
	int		engPoint;
	int 	atckDmg;
};

#endif