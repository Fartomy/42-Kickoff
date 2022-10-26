/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:51:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:32 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

};

#endif