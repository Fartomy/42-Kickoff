NAME			=	shrubotodential

SRCS			=	Bureaucrat.cpp main.cpp	AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
LIB				=	Bureaucrat.hpp AForm.hpp	PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

OBJS			=	$(SRCS:%.cpp=%.o)

CC				= 	c++
RM				= 	rm -rf
CPPFLAGS		= 	-Wall -Wextra -Werror -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS) $(LIB)
				$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS) ShrubberyForm_shrubbery

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:
				norminette *.[ch]

.PHONY:			all clean fclean re bonus