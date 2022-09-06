/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:10:52 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/10 13:20:22 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
	{
		str[n] = (unsigned char )c;
	}
	return (str);
}

/*int main()
{
	char a[] = "selam";
	printf("%s\n", ft_memset(a, 'x', 2));

	char a1[] = "selam";
	printf("%s", memset(a1, 'x', 2));
}*/