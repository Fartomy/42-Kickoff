/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:41:47 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/13 15:43:53 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	while (src[i] != '\0' && size > (dstlen + 1))
		dst[dstlen++] = src[i++];
	dst[dstlen] = '\0';
	return (dstlen + ft_strlen((char *)(src + i)));
}

//int main()
//{
//char a[7] = "selam";
//char b[7] = "hello";

////char a1[7] = "selam";
//// 	char b2[7] = "hello";

//printf("%zu\n", ft_strlcat(a, b, 7));
//printf("%s", a);
//// printf("%zu\n", strlcat(a1, b2, 7));
//// printf("%s", a1);
//// 	//if (a[7] == '\0')
//// 	   //printf("%s", "has a null value"); 
//// 	//
//}