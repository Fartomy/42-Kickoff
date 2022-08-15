NAME	=	push_swap

RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m

OBJ_DIR		= outputs/

SRCS	=	push_swap.c		push_swap_utils.c	push_swap_tools.c	a_and_b_stack_funcs.c	a_stack_funcs.c	\
			b_stack_funcs.c		sub_zero.c		push_swap_tools2.c	for_3_5_sort.c	push_swap_checks.c

OBJS	=	$(SRCS:.c=.o)

CC		=	@gcc
RM		=	@rm -rf 
OUT		=	-o push_swap
CFLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW)>- Compiling... [$(NAME)] $(RESET)"
			$(CC) $(CFLAGS) $(OUT) $(OBJS) -ggdb
			@echo "$(GREEN)>- Finished! $(RESET)"

clean:
			@echo "$(RED)>- Deleting... [$(OBJS)] $(RESET)"
			$(RM) $(OBJS)
			@echo "$(BLUE)>- Successfully! $(RESET)"

fclean:		clean
			$(RM) $(NAME)
			

re:	fclean $(NAME)

norm:		
			norminette *.[ch]

.PHONY:	all clean fclean re