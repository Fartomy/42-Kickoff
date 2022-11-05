NAME			=	pure

SRCS			=	Animal.cpp	Cat.cpp	Dog.cpp	main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
LIB				=	Animal.hpp	Cat.hpp	Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

OBJS			=	$(SRCS:%.cpp=%.o)

CC				= 	c++
RM				= 	rm -rf
CPPFLAGS		= 	-Wall -Wextra -Werror -std=c++98

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