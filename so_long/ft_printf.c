/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:43:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/11 14:55:58 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	type_srch(va_list vag, char str, int a)
{
	if (str == '%')
		a = write(1, "%", 1);
	else if (str == 'c')
		a = ft_putchar(va_arg(vag, int));
	else if (str == 's')
		a = ft_putstr(va_arg(vag, char *));
	else if (str == 'd')
		a = ft_putnbr(va_arg(vag, int));
	else
		str++;
	return (a);
}

int	ft_printf(const	char *s, ...)
{
	int		a;
	va_list	vag;

	a = 0;
	va_start(vag, s);
	while (*s)
	{
		if (*s == '%')
			a += type_srch(vag, *(++s), a);
		else
			a += ft_putchar(*s);
		s++;
	}
	va_end(vag);
	return (a);
}
