/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:45 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/02/23 17:22:04 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_16base(unsigned long n, char *base)
{
	static char	str[50];
	char		*s;

	s = &str[49];
	*s = 0;
	*(--s) = base[n % 16];
	n /= 16;
	while (n != 0)
	{
		*(--s) = base[n % 16];
		n /= 16;
	}
	return (s);
}

int	for_p(unsigned long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	cnt += ft_putstr("0x");
	cnt += ft_putstr(hex_16base(n, "0123456789abcdef"));
	return (cnt);
}

int	ft_putnbr_unsgnd(unsigned int n)
{
	int				cnt;
	unsigned int	i;
	char			str[10];

	cnt = 0;
	i = 0;
	if (n == 0)
		cnt += ft_putchar('0');
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		cnt += ft_putchar(str[i]);
	return (cnt);
}
