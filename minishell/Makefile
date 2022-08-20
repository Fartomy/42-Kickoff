NAME	=	minishell
LIBFT	= 	libft/libft.a
INC		= ./inc/
INC_LT	= ./libft/libft.h


RESET	=	\033[0m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RED		=	\033[31m


SRCS	= $(shell find src -type f -name "*.c")
OBJS	= $(SRCS:src/%.c=src/bin/%.o)
BIN		= ./src/bin
LIB		= ./lib/.readline_lib


CC		=	@gcc
RM		=	@rm -rf 
OUT		=	-o minishell
CFLAGS	=	-Wall -Werror -Wextra
LRDL	= 	-lreadline

all: $(LIB)	$(LIBFT) $(NAME)

$(LIB):
	make -C ./lib

$(BIN):
	@mkdir $(BIN)

$(LIBFT):
	@make -C libft/

$(NAME): $(BIN)	$(LIBFT) $(OBJS) 
			@echo "$(YELLOW)>- Compiling... [$(NAME)] $(RESET)"
			$(CC) $(LRDL) $(CFLAGS) $(LIBFT) $(OUT) $(OBJS) # -fsanitize=address -g
			@echo "$(GREEN)>- Finished! $(RESET)"

$(BIN)%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_LT) -I$(INC)

clean:
			@echo "$(RED)>- Deleting... [$(NAME)] $(RESET)"
			$(RM) $(OBJS)
			$(RM) $(BIN)
			@make clean -C libft/
			@echo "$(BLUE)>- Successfully! $(RESET)"

fclean:		clean
			$(RM) $(NAME)

			@make fclean -C libft/

ffclean: fclean
	@make fclean -C lib/

re:	fclean all

norm:		
			norminette *.[ch]

.PHONY:	all clean fclean re