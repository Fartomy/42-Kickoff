/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:41:58 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/08 19:34:33 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (char *)malloc(count * size);
	if (!str)
		return (0);
	return (ft_memset(str, '\0', count * size));
}

/*int main()
{
	int *a;
	a = ft_calloc(3, sizeof(int));
	printf("%d", a[2]);
	return (0);
}*/