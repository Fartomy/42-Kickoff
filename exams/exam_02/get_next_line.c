#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void *ft_free(void *f)
{
	free (f);
	return(NULL);
}

char *get_next_line(int fd)
{
	char buff;
	int i;
	int x;
	char *ret;

	ret = (char *)malloc(sizeof(char) * 9999);
	buff = 0;
	i = 1;
	x = 0;

	while(i > 0)
	{
		i = read(fd, &buff, 1);
		if(i <= 0)
			break ;
		ret[x++] = buff;
		if(buff == '\n')
			break ;
	}
	ret[x] = 0;
	if(!*ret)
		return (ft_free(ret));
	return(ret);
}

/*int main()
{
	int fd;

	fd = open("union.c", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}*/
