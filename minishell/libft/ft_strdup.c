/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:08:59 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/19 15:08:03 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;
	char	*str2;
	size_t	cnt;

	str1 = (char *)s1;
	cnt = ft_strlen(str1);
	str2 = malloc(sizeof(char) * (cnt + 1));
	if (!str2)
		return (0);
	str2[cnt] = '\0';
	return (ft_memcpy(str2, str1, cnt));
}
