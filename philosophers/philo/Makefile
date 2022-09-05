NAME	=	philo

RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m

SRCS	=	philosophers.c	philo_tools.c	philo_utils.c	philo_behaviours.c	philo_checks.c

OBJS	=	$(SRCS:.c=.o)

CC		=	@gcc #-fsanitize=thread -g
RM		=	@rm -rf 
OUT		=	-o philo
CFLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW)>- Compiling... [$(NAME)] $(RESET)"
			$(CC) $(CFLAGS) $(OUT) $(OBJS)
			@echo "$(GREEN)>- Finished! $(RESET)"

clean:
			@echo "$(RED)>- Deleting... [$(NAME)] $(RESET)"
			$(RM) $(OBJS)
			@echo "$(BLUE)>- Successfully! $(RESET)"

fclean:		clean
			$(RM) $(NAME)
			

re:	fclean $(NAME)

norm:		
			norminette *.[ch]

.PHONY:	all clean fclean re
