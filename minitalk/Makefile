SRCSERVER			= ft_printf.c	server.c	minitalk_utils.c
SRCCLIENT			= ft_printf.c	client.c	minitalk_utils.c

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

OBJSERVER		= $(SRCSERVER:.c=.o)

OBJSCLIENT 		= $(SRCCLIENT:.c=.o)

NAME			= minitalk.a

all:			$(NAME)

$(NAME): server client $(OBJSERVER) $(OBJSCLIENT)
		
server: 
		$(CC) -o server $(SRCSERVER) $(CFLAGS)

client: 
		$(CC) -o client $(SRCCLIENT) $(CFLAGS)

clean:
				$(RM) $(OBJSERVER) $(OBJSCLIENT)

fclean:			clean
				$(RM) server
				$(RM) client

re:				fclean $(NAME)

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re norm