/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:22:47 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/10 13:43:53 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;
	char	*hystck;

	hystck = (char *)haystack;
	x = 0;
	i = 0;
	if (ft_strlen(needle) == 0)
		return (hystck);
	while (hystck[x] != '\0' && len >= ft_strlen(needle))
	{
		while (hystck[i + x] == needle[i] && \
			hystck[i + x] != '\0' && needle[i] != '\0')
		i++;
		if (needle[i] == '\0')
			return (&hystck[x]);
		x++;
		len--;
	}
	return (0);
}

/*int main()
{
	printf("%s", ft_strnstr("merhaba", "hab", 3));
	return(0);
}*/