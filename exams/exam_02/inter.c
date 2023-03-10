#include <unistd.h>

int fnc(char c, char *str, int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		if(c == str[i])
			return(1);
		i++;
	}
	return(0);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != 0)
		i++;
	return(i);
}

int main(int ac, char **av)
{
	int i;
	char *s1;
	char *s2;

	i = 0;
	s1 = av[1];
	s2 = av[2];

	if(ac == 3)
	{
		while(s1[i])
		{
			if(!fnc(s1[i], s1, i) && fnc(s1[i], s2, ft_strlen(s2)))
				write(1, &s1[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}
