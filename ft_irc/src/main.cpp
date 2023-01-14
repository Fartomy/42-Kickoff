/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:01:56 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/01/04 12:06:16 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"
#include "../inc/Server.hpp"

string g_PASS;
int main( int ac, char* av[] )
{
    if (ac == 3)
    {
		try
		{
			int port = atoi(av[1]);
			string passw(av[2]);
			g_PASS = passw;
			Server serv(port, av[2]);

			if ( serv.sockStart() == -1 )
				return 1;
			if ( serv.sockScan() == -1 )
				return 1;
		}
		catch ( const std::exception &e )
		{
			cerr << RED << e.what() << endl << YLW <<
				"Port must be between [1024 - 65535]" << RESET << endl;
			exit(1);
		}
	}
    else
	{
		cerr << RED << "Missing or More Arguments!" << endl << YLW <<
			"Please Type This Format:"<< endl << CYN <<"./ircserv <port> <servPass>" << RESET << endl;
	}
	 return 0;
}