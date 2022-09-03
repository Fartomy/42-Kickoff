/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:08:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/03 16:55:26 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **parse)
{
	int i;

	i = 0;
	if(!parse[++i])
	{
		printf("");
		return ;
	}
	while (parse[i])
	{
		if(equal_finder(parse[i]) == 0)
		{
			int x;
			char *name;

			x = -1;
			while (data.env[++x])
			{
				name = env_name_getter(data.env[x]);	
				if(ft_strcmp(name, parse[i]) == 0)
				{
					free(name);
					char *tmp;
					while (data.env[x] && data.env[x + 1])
					{
						tmp = data.env[x + 1];
						data.env[x + 1] = data.env[x];
						data.env[x++] = tmp;
					}
					if(data.env[x + 1] == 0)
					{
						free(data.env[x]);
						data.env[x] = 0;
						data.env = ft_rrealloc(data.env, ft_arglen(data.env));
						break;
					}
				}
				if(name)
					free(name);
			}
			x = -1;
			while (data.export[++x])
			{
				name = env_name_getter(data.export[x]);	
				if(ft_strcmp(name, parse[i]) == 0)
				{
					free(name);
					char *tmp;
					while (data.export[x] && data.export[x + 1])
					{
						tmp = data.export[x + 1];
						data.export[x + 1] = data.export[x];
						data.export[x++] = tmp;
					}
					if(data.export[x + 1] == 0)
					{
						free(data.export[x]);
						data.export[x] = 0;
						data.export = ft_rrealloc(data.export, ft_arglen(data.export));
						break;
					}
				}
				if(name)
					free(name);
			}
		}
		else
		{
			data.status = 1;
			printf("minishell: %s: `%s': not a valid identifier\n", parse[0], parse[i]);
		}
		i++;
	}
	
}