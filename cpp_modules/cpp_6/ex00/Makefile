NAME			=	convert

SRCS			=	main.cpp TypeCast.cpp Utils.cpp
LIB				=	TypeCast.hpp

OBJS			=	$(SRCS:%.cpp=%.o)

CC				= 	c++
RM				= 	rm -rf
CPPFLAGS		= 	-Wall -Wextra -Werror -std=c++98 -ggdb

all:			$(NAME)

$(NAME):		$(OBJS) $(LIB)
				$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:
				norminette *.[ch]

.PHONY:			all clean fclean re bonus