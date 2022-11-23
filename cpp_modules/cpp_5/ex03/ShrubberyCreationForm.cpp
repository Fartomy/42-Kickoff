/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:28:00 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/23 14:28:01 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( string target ) : AForm( target, 137, 145 ) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

void ShrubberyCreationForm::execute( const Bureaucrat &obj ) const
{
	if ( getExecGrade() < obj.getGrade() )
		throw GradeTooLowException();
	if ( getIsSigned() == false )
		throw NotSignedException();
	exeAction( obj );
}

void ShrubberyCreationForm::exeAction( const Bureaucrat &obj ) const
{
	( void )obj;
	string str = getName() + "_shrubbery";

	ofstream file( str.c_str() );
	file << "                C++ " << endl;
	file << "                \\_/ " << endl;
	file << "                 | " << endl;
	file << "                 * " << endl;
	file << "                *** " << endl;
	file << "               ***** " << endl;
	file << "              ***|*** " << endl;
	file << "             ****O**** " << endl;
	file << "            *********** " << endl;
	file << "           ***|***|***** " << endl;
	file << "          ****$***|**|*** " << endl;
	file << "         **|******O**+**** " << endl;
	file << "        ***@*****|********* " << endl;
	file << "       ****|*****@******|*** " << endl;
	file << "      **|**+************$**** " << endl;
	file << "     ***|*****|***|***|****|** " << endl;
	file << "    ****$*****|***O***|****@*** " << endl;
	file << "   ***********+*******+********* " << endl;
	file << "  **|**|**|*###########**|*|**|** " << endl;
	file << "    |  |  | ###########  | |  |    " << endl;
	file << "    $  |  | ###########  | |  O    " << endl;
	file << "       |  | ###########  $ |       " << endl;
	file << "       |  O ###########    |       " << endl;
	file << "       @    ###########    +       " << endl;
	file << "            ###########            " << endl;
	file << "           #############           " << endl;
	file << "          ###############          " << endl;
	file << "_O__+_@__#################__$_+_@__" << endl;
	file.close();
	cout << str << " File is created!" << endl;
}