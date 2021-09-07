##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for evalexpr
##

SRC_NM		= nm/src/file_parse.c \
			nm/src/help.c \
			nm/src/main.c \
			nm/src/parser.c \
			nm/src/sort.c \
			nm/src/get_type.c \
			nm/src/error_handling.c

SRC_OBJ		= objdump/src/main.c \
			objdump/src/help.c \
			objdump/src/file_header64.c \
			objdump/src/file_header32.c \
			objdump/src/parse_file32.c \
			objdump/src/parse_file64.c \
			objdump/src/parser.c \
			objdump/src/file_sections64.c

CFLAGS = -I include/

CFLAGS += -g -W -Wall -Wextra -Werror

OBJ_NM	=	$(SRC_NM:.c=.o)
OBJ_OBJ	=	$(SRC_OBJ:.c=.o)

NAME_NM	=	my_nm
NAME_OBJ=	my_objdump

RM	=	rm -f

all:		nm	objdump

nm:			$(NAME_NM)
objdump:	$(NAME_OBJ)

$(NAME_NM):	$(OBJ_NM)
		gcc $(CFLAGS) -o $(NAME_NM) $(OBJ_NM)
$(NAME_OBJ):$(OBJ_OBJ)
		gcc $(CFLAGS) -o $(NAME_OBJ) $(OBJ_OBJ)
clean:
	$(RM) $(OBJ_NM)
	$(RM) $(OBJ_OBJ)


fclean: clean
	$(RM) $(NAME_NM) $(OBJ_NM)
	$(RM) $(NAME_OBJ) $(OBJ_OBJ)

re:	fclean all

.PHONY:	all clean fclean re
