/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:27:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:27:13 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::endl;
using std::string;
using std::cout;
using std::ofstream;

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( string target );
	~ShrubberyCreationForm();
	void execute( const Bureaucrat &obj ) const;
	void exeAction( const Bureaucrat &obj ) const;
};

#endif