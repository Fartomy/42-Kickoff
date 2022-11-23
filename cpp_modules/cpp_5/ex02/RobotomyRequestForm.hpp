/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:56 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:57 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <time.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::endl;
using std::cout;
using std::string;

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm( string target );
	~RobotomyRequestForm();
	void execute( const Bureaucrat &obj ) const;
	void exeAction( const Bureaucrat &obj ) const;
};

#endif