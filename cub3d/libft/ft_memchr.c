/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:56:33 by syildiri          #+#    #+#             */
/*   Updated: 2022/01/13 03:07:05 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const char	*k;
	int			i;

	k = (const char *)ptr;
	i = 0;
	while (n--)
	{
		if (k[i] == (char)c)
		{
			return ((void *)&ptr[i]);
		}
		else
			i++;
	}
	return (0);
}
