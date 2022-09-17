/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:08:59 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/08 19:58:55 by ftekdrmi         ###   ########.fr       */
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

/*int main()
{
	char a[] = "bilgisayar";
	printf("%s", ft_strdup(a));
}*/