/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:27:39 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:27:40 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

using std::cout;
using std::endl;
using std::string;

class Intern
{
public:
	Intern();
	~Intern();

	struct FormNotFound : public exception
	{
		const char * what() const throw();
	};

	AForm* makeForm( string name, string target );
};

#endif