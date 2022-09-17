/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:17:56 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/10 12:31:37 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	idx;

	idx = 0;
	while (n-- > 0)
	{
		if (((unsigned char *)s)[idx] == (unsigned char)c)
			return ((void *)(s + idx));
		idx++;
	}
	return (0);
}

/*int main()
{
	char a[] = "ali";
	ft_memchr(a, 'l', 2);
	printf("%p\n", a);
}*/