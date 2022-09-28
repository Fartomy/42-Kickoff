/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:47:41 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/12 19:09:06 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		index;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	index = 0;
	if (d == s)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (d);
	}
	index = 0;
	while (index < (int)len)
	{
		d[index] = s[index];
		index++;
	}
	return (d);
}

/*int main()
{
    char dst[20] = "bilgisayar";
    char src[20] = "bilgisa";

    char dst2[20] = "bilgisayar";
    char src2[20] = "bilgisa";

    ft_memmove(dst, src, 10);
    memmove(dst2, src2, 10);

    printf("%s\n", dst);
    printf("%s", dst2);
}*/