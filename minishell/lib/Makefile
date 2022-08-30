# Colors

BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;34m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"
# Files

DIR				= $(shell echo $(PWD))
RM				= rm -rf


# Directories

NAME				= ./.rdl

# Rules

all : $(NAME)

$(NAME):
	@curl -O http://ftp.gnu.org/gnu/readline/readline-8.2-rc1.tar.gz
	@gunzip -c readline-8.2-rc1.tar.gz | tar xopf -
	@mv readline-8.2-rc1 readline
	@/bin/sh -c "cd readline && sh ./configure --prefix=$(DIR)/lib/readline"
	@make install -C readline
	@rm -f readline-8.2-rc1.tar.gz
	@mkdir $(NAME)
	@clear

fclean : 
	@echo $(RED)">- Deleting readline..." $(END)
	@$(RM) ./readline $(NAME)
	@echo $(BLUE)">- Successfully! [$(NAME)]" $(END)

re : fclean all

.PHONY: all  fclean re