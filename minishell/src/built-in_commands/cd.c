/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:53:58 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/15 22:52:30 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cd(char **parse)
{
	if(!parse[1])
	{
		int i;

		i = 0;
		while (data.env[i])
		{
			if(ft_strncmp(data.env[i], "HOME", 4) == 0)
			{
				char *home_value;
				
				home_value = ft_strdup(data.env[i]);
				home_value = env_getter(home_value);
				chdir(home_value);
				free(home_value);
			}
			i++;
		}
	}
	else if(ft_strcmp(parse[1], "-") == 0) // OLDPWD değeri güncellenmeli ve OLDPWD program ilk açıldığında set edilemeyeceğinden bu hata verilmeli: "bash: cd: OLDPWD not set"
	{
		int i;

		i = 0;
		while (data.env[i])
		{
			if(ft_strncmp(data.env[i], "OLDPWD", 6) == 0)
			{
				char *oldpwd_value;

				oldpwd_value = ft_strdup(data.env[i]);
				oldpwd_value = env_getter(oldpwd_value);
				chdir(oldpwd_value);
				printf("%s\n", oldpwd_value);
				free(oldpwd_value);
			}
			i++;
		}
		
	}
	else
	{
		int i;
		
		i = chdir(parse[1]);
		if(i == -1)
			printf("minishell: %s: %s: No such file or directory\n", parse[0], parse[1]);
	}
}