NAME			=	cub3D
INC				=	./inc/
LIBFT			=	libft/libft.a

RESET			=	\033[0m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
RED				=	\033[31m

SRCS			=	$(shell find src -type f -name "*.c")
OBJS			=	$(SRCS:src/%.c=src/bin/%.o)
BIN				=	./src/bin
LIB				=	./minilibx_macos/libmlx.a

CC				=	@gcc
RM				=	@rm -rf
CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-framework OpenGL -framework AppKit

all:			$(LIB) $(LIBFT) $(NAME)

$(LIB) : 
		@make -C ./mlx

$(BIN):
	@mkdir $(BIN)

$(LIBFT):
	@make -C libft/

$(NAME):	$(BIN) $(LIBFT) $(OBJS)
			@echo "$(YELLOW)>- Compiling... [$(NAME)] $(RESET)"
			@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(MLXFLAGS) -o $(NAME) $(LIB)
			@echo "$(GREEN)>- Finished! $(RESET)"

clean:
			@echo "$(RED)>- Deleting... [$(NAME)] $(RESET)"
			@$(RM) $(OBJS)
			@$(RM) $(BIN)
			@make clean -C libft/
			@echo "$(BLUE)>- Successfully! $(RESET)"

fclean:			clean
				@$(RM) $(NAME)
				@make fclean -C libft/

re:				fclean $(NAME)

$(BIN)%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re bonus