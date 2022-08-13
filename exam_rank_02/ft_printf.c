#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int ft_putchar(char c)
{
	int cnt;

	cnt = 0;
	cnt += write(1, &c, 1);
	return(cnt);
}

int ft_putstr(char *str)
{
	int cnt;
	int x;

	x = 0;
	cnt = 0;

	while(str[x] != '\0')
	{
		cnt += write(1, &str[x], 1);
		x++;
	}
	return(cnt);
}

int ft_putnbr(int a)
{
	int cnt;

	cnt = 0;

	if(a < 0)
	{
		cnt += ft_putchar('-');
		a *= -1;
	}


	if(a > 9)
		cnt += ft_putnbr(a / 10);
	cnt += ft_putchar("0123456789"[a % 10]);
	return (cnt);
}

char *hex_16base(unsigned long x, char *base)
{
	static char str[50];
	char *s;

	s = &str[49];
	*s = 0;
	*(--s) = base[x % 16];
	x /= 16;
	while(x != 0)
	{
		*(--s) = base[x % 16];
		x /= 16;
	}
	return(s);
}

int type_srch(va_list vag, char str, int x)
{
	if(str == 's')
		x = ft_putstr(va_arg(vag, char *));
	else if(str == 'd')
		x = ft_putnbr(va_arg(vag, int));
	else if(str == 'x')
		x = ft_putstr(hex_16base(va_arg(vag, unsigned long), "0123456789abcdef"));
	return(x);
}		


int ft_printf(const char *s, ...)
{
	int cnt;
	va_list vag;

	cnt = 0;
	va_start(vag, s);

	while(*s)
	{
		if(*s == '%')
			cnt += type_srch(vag, *(++s), cnt);
		else
			cnt += ft_putchar(*s);
		s++;
	}
	va_end(vag);
	return(cnt);
}

int main()
{
	int x;

	x = 0;

	x = ft_printf("%s %d %x","selam",42,0);

	printf("toplam karakter sayı: %d", x);
}
