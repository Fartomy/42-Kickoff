/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:43:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/02/23 17:23:22 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_srch(va_list vag, char str, int a)
{
	if (str == '%')
		a = write(1, "%", 1);
	else if (str == 'c')
		a = ft_putchar(va_arg(vag, int));
	else if (str == 's')
		a = ft_putstr(va_arg(vag, char *));
	else if (str == 'p')
		a = for_p(va_arg(vag, unsigned long));
	else if (str == 'd')
		a = ft_putnbr(va_arg(vag, int));
	else if (str == 'i')
		a = ft_putnbr(va_arg(vag, int));
	else if (str == 'u')
		a = ft_putnbr_unsgnd(va_arg(vag, unsigned int));
	else if (str == 'x')
		a = ft_putstr(hex_16base(va_arg(vag, unsigned int), \
		"0123456789abcdef"));
	else if (str == 'X')
		a = ft_putstr(hex_16base(va_arg(vag, unsigned int), \
		"0123456789ABCDEF"));
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

//int main()
//{
//	char b[] = "a";
//	int i;
//	int x;
//	i = ft_printf("ft_printf  value: %p\n", b);
//	x = printf("org_printf value: %p\n", b);
//	printf("total: %d\n", i);
//	printf("total: %d\n", x);
//	return (0);
//}
