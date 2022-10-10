/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:56:39 by syildiri          #+#    #+#             */
/*   Updated: 2022/01/13 03:07:13 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*k ;
	const char		*s;
	int				i;

	k = (unsigned char *)dest;
	s = (const char *)src;
	i = 0;
	if (s == NULL && k == NULL)
		return (NULL);
	while (n--)
	{
		k[i] = s[i];
		i++;
	}
	dest = k;
	return (dest);
}
