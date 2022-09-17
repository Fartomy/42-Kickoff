/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:27:54 by a_furkan          #+#    #+#             */
/*   Updated: 2022/01/12 18:49:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	idx;

	if (!s)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		str[idx] = (*f)(idx, str[idx]);
		idx++;
	}
	return (str);
}
