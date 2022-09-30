/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:17:09 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/30 16:17:10 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    if(!av[1])
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else if(av[1] && !av[2])
    {
        int i = -1;

        while(av[1][++i])
            av[1][i] = toupper(av[1][i]);
        std::cout << av[1] << std::endl;
    }
    else
    {
        std::string space = " ";
        int i = -1;
        int x;
        while(av[++i])
        {
            x = -1;
            while(av[i][++x])
                av[i][x] = toupper(av[i][x]);
        }
        i = 1;
        while(av[i])
            std::cout << av[i++] + space;
        std::cout << std::endl;
    }
}