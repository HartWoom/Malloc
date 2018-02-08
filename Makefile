##
## EPITECH PROJECT, 2018
## Malloc
## File description:
## Makefile to compile malloc library
##

SRC	=	my_malloc.c	/
		list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

CFLAGS	+=	-fpic -W -Wall -Wextra -I.

CC	=	gcc

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
