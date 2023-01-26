NAME    = ft_container
CC      = c++
FLAGS   = -Wall -Werror -Wextra -std=c++98
SRCS    = src/main3.cpp		#src/main2.cpp		src/main.cpp

OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(FLAGS)

clean:
	rm -rf $(OBJS) $(NAME)

fclean: clean
	rm -rf $(NAME)

re: clean $(NAME)

.PHONY  : $(NAME) all fclean clean re