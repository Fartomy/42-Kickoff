/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:13:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:13:05 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

using std::string;
using std::cout;
using std::endl;
using std::exception;
using std::ostream;
using std::cerr;

class Bureaucrat
{
public:
	struct GradeTooHighException : public exception
	{
		const char* what() const throw();
	};
	struct GradeTooLowException : public exception
	{
		const char* what() const throw();
	};

    Bureaucrat( const string _name, int _grade );
    ~Bureaucrat();

    int getGrade( void ) const;
    string getName( void ) const;

	void incGrade( void );
	void decGrade( void );

	void signForm( Form &form, Bureaucrat &brc );
	void executeForm( Form const &form );

private:
    const string name;
    int grade;
};

ostream& operator << ( ostream &ost, const Bureaucrat &obj );

#endif