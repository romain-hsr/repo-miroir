##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Will Makefile
##

SCR	=	$(wildcard lib/*.c)	\
		$(wildcard info_env/*.c)	\
		$(wildcard command_recode/*.c)	\
		$(wildcard command_recode/cd/*.c)	\
		$(wildcard redirection/*.c)	\
		exit.c	\
		pipe.c	\
		main.c	\

NAME	=	mysh

all: $(NAME)

$(NAME):
		gcc -o $(NAME) $(SCR) -g -Wall -Wextra

clean:
		rm -f $(NAME)

fclean: clean

re:	fclean all
