/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:27:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:27:54 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( string target ) : AForm(target, 45, 72) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

void RobotomyRequestForm::execute( const Bureaucrat &obj ) const
{
	if ( getExecGrade() < obj.getGrade() )
		throw GradeTooLowException();
	if( getIsSigned() == false )
		throw NotSignedException();
	exeAction( obj );
}

void RobotomyRequestForm::exeAction( const Bureaucrat &obj ) const
{
	( void )obj;
	int tmp;

	srand( time( NULL ) );
	tmp = rand() % 100;
	if ( tmp < 50 )
		cout << getName() << " is succesfully robotomized" << endl;
	else
		cout << getName() << " is not robotomized" << endl;
}