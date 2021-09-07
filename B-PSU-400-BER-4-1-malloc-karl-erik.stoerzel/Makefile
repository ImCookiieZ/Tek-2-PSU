##
## EPITECH PROJECT, 2021
## makefile
## File description:
## test
##

CC = gcc
CFLAGS += -I include/
CFLAGS += -Wall -Wextra -Werror -g
CFLAGS += -fPIC

rm = rm -f

NAME = libmy_malloc.so

SRC_DIR = src/

SRC_FILES = src/malloc.c \
			src/free.c \
			src/realloc.c \
			src/calloc.c \
			src/reallocarray.c \
			src/bestfitalgo.c

SRC = 	$(appprefix $(SRC_DIR), $(SRC_FILES))

OBJ = 	$(SRC_FILES:.c=.o)

all: 	$(NAME)

run: all
	gcc main.c -L. -lmy_malloc
	./a.out

$(NAME): $(OBJ)
	$(CC) -fPIC -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
re:	fclean all

.PHONY: all clean fclean re