NAME			= cub3D
LIBFT			= libft/libft.a

RESET			=	\033[0m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
RED				=	\033[31m

SRCS			=	cub3d.c		cub3d_utils.c	cub3d_map_read.c	cub3d_checks.c	cub3d_checks2.c	cub3d_checks3.c	cub3d_parse.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc -ggdb
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

LIB				= ./mlx/libmlx.a

all:			$(LIB) $(LIBFT) $(NAME)

$(LIB) : 
		make -C ./mlx

$(LIBFT):
	@make -C libft/

$(NAME):	$(LIBFT) $(OBJS)
			@echo "$(YELLOW)>- Compiling... [$(NAME)] $(RESET)"
			@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -framework OpenGL -framework AppKit -o $(NAME) $(LIB)
			@echo "$(GREEN)>- Finished! $(RESET)"

clean:
			@echo "$(RED)>- Deleting... [$(NAME)] $(RESET)"
			@$(RM) $(OBJS)
			@make clean -C libft/
			@echo "$(BLUE)>- Successfully! $(RESET)"

fclean:			clean
				@$(RM) $(NAME)
				@make fclean -C libft/

re:				fclean $(NAME)

%.o: %.c
	 @$(CC) $(CFLAGS) -I./mlx -c $< -o $@

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re bonus