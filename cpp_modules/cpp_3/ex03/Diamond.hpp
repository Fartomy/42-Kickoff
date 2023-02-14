/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamond.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:29:20 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:29:57 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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