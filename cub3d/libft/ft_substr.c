/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:01:19 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/13 15:56:56 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) <= start)
	{
		tmp = malloc(sizeof(char) * 1);
		if (!tmp)
			return (0);
		tmp[0] = '\0';
		return (tmp);
	}
	tmp = (char *)malloc(sizeof(*s) * (len + 1));
	if (!tmp)
		return (0);
	while (index < len)
		tmp[index++] = s[start++];
	tmp[index] = 0;
	return (tmp);
}

/*int main()
{
    printf("%s", ft_substr("abcdef", 1, 2));
}*/