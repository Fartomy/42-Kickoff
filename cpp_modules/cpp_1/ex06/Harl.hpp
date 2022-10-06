/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:19:52 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/06 23:19:53 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Harl
{
public:
	Harl()
	{
		fncPtr[0] = &Harl::debug;
		fncPtr[1] = &Harl::info;
		fncPtr[2] = &Harl::warning;
		fncPtr[3] = &Harl::error;
	};
	void	complain(string level);

private:
	void	(Harl::*fncPtr[4])();
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};