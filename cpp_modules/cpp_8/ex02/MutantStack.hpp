/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:31:55 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:31:56 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using std::cout;
using std::endl;

template<class T> class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	MutantStack( const MutantStack& cpy )
	{
		*this = cpy;
	};
	MutantStack& operator = ( const MutantStack& )
	{
		return *this;
	}
	~MutantStack(){};
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

#endif