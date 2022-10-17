/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:19:42 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/06 23:19:43 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Harl
{
public:
	Harl();
	void	complain(string level);

private:
	void	(Harl::*fncPtr[4])();
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};