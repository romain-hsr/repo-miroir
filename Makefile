##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Will Makefile
##

SCR	=	main.c	\

NAME	=	mysh

all: $(NAME)

$(NAME):
		gcc -o $(NAME) $(SCR) -g -Wall -Wextra

clean:
		rm -f $(NAME)

fclean: clean

re:	fclean all
