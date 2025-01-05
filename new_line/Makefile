NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
BUFFER_SIZE ?= 42
$(info Compiling buffer with BUFFER_SIZE: $(BUFFER_SIZE))

SRC := get_next_line.c get_next_line_utils.c 
OBJS := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fv $(OBJS)

fclean: clean
	rm -fv $(NAME)

re: fclean all

.PHONY: all clean fclean re