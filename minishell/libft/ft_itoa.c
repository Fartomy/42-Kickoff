/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:40:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/10 12:14:42 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		temp;
	int		idx;

	temp = n;
	idx = 1;
	while (temp && idx++)
		temp /= 10;
	str = (char *)malloc((sizeof(char)) * (n <= 0) + idx);
	if (!str)
		return (0);
	str += (n < 0) + idx - 1 + (n == 0);
	*str = '\0';
	if (n == 0)
		*(--str) = '0';
	idx = (n >= 0) * 2 - 1;
	while (n)
	{
		*(--str) = (n % (10 * idx) * idx + '0');
		n /= 10;
	}
	if (idx < 0)
		*(--str) = '-';
	return (str);
}
