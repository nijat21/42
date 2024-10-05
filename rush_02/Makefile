NAME = rush-02
SRC = main.c
OBJ = $(SRC: .c=.0)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC)	$(CFLAGS)	-o	$(NAME)	$(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re:
	fclean(all)