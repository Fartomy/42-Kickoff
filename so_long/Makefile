SRCS			=	so_long.c	images.c	map_read.c		set_zero.c		so_long_utils.c		key_utils.c		map_check.c\
					some_funcs.c	game_free.c		ft_printf.c		ft_printf_utils.c	map_check_2.c
										

OBJS			= $(SRCS:.c=.o)

CC				= gcc #-fsanitize=address -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= so_long
LIB				= ./mlx/libmlx.a

all:			$(LIB) $(NAME)

$(LIB) : 
	make -C ./mlx

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -framework OpenGL -framework AppKit -o $(NAME) $(LIB)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

%.o: %.c
	 $(CC) $(CFLAGS) -I./mlx -c $< -o $@

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re bonus