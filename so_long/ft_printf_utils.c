/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:33:29 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/11 14:25:29 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	int	cnt;

	cnt = 0;
	cnt += write(1, &c, 1);
	return (cnt);
}

int	ft_putnbr(int n)
{
	unsigned int	i;
	int				cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt += ft_putchar('-');
		i = -n;
	}
	else
		i = n;
	if (i > 9)
	{
		cnt += ft_putnbr(i / 10);
		cnt += ft_putchar((i % 10) + '0');
	}
	else
		cnt += ft_putchar(i + '0');
	return (cnt);
}

int	ft_putstr(char *s)
{
	int	idx;
	int	cnt;

	cnt = 0;
	idx = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[idx] != '\0')
	{
		cnt += write(1, &s[idx], 1);
		idx++;
	}
	return (cnt);
}
