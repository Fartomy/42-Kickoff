/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:51 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:52 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::string;
using std::endl;
using std::cout;

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm( string target );
	~PresidentialPardonForm();

	void execute( const Bureaucrat &obj ) const;
	void exeAction( const Bureaucrat &obj ) const;
private:
};


#endif
