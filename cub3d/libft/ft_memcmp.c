/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:56:36 by syildiri          #+#    #+#             */
/*   Updated: 2022/01/13 03:04:19 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*k;
	const unsigned char	*j;
	size_t				i ;

	i = 0;
	k = (const unsigned char *)ptr1;
	j = (const unsigned char *)ptr2;
	while (n--)
	{
		if (k[i] == j[i])
		{
			i++;
		}
		else
			return (-(j[i] - k[i]));
	}
	return (0);
}
