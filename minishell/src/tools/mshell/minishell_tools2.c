/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:04:24 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/06 15:19:20 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**storage_and_copy(char **env)
{
	int		i;
	int		x;
	char	**str;

	str = ft_calloc(sizeof(char *), ft_arglen(env) + 1);
	i = -1;
	while (env[++i])
		str[i] = ft_calloc(sizeof(char), ft_strlen(env[i]) + 1);
	i = -1;
	while (env[++i])
	{
		x = -1;
		while (env[i][++x])
			str[i][x] = env[i][x];
	}
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			t;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (str2)
	{
		t = 0;
		while (str1[t] != '\0' && str2[t] != '\0' && str1[t] == str2[t])
			t++;
		return (str1[t] - str2[t]);
	}
	return (1);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*temp;

	temp = malloc(sizeof(char) * size);
	ft_strlcpy(temp, ptr, ft_strlen(ptr) + 1);
	free(ptr);
	return (temp);
}

char	**ft_rrealloc(char **ptr, size_t size)
{
	char	**temp;
	int		i;

	i = -1;
	temp = malloc(sizeof(char *) * size + 1);
	while (ptr[++i])
	{
		temp[i] = malloc(sizeof(char) * (ft_strlen(ptr[i]) + 1));
		temp[i] = ft_memcpy(temp[i], ptr[i], ft_strlen(ptr[i]) + 1);
	}
	temp[i] = 0;
	ft_free(ptr);
	return (temp);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
