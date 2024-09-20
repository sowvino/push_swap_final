NAME = push_swap

SOURCES = main.c \
          error_handling.c \
          push_swap_init.c \
          push_swap.c \
          push.c \
          reverse_rotate.c \
          rotate.c \
          ft_split.c \
          stack_init.c \
          stack_utilis.c \
          swap.c \
          algorithm.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCS = push_swap.h

RM = rm -f

$(NAME): $(OBJECTS) $(INCS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .c .o
