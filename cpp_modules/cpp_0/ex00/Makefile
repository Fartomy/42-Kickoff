NAME			=	megaphone

SRCS			=	megaphone.cpp
					
OBJS			=	$(SRCS:%.cpp=%.o)

CC				= 	g++
RM				= 	rm -rf
CPPFLAGS		= 	-Wall -Wextra -Werror -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)


clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re bonus
