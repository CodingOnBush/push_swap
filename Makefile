CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJDIR = objs
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
NAME = push_swap

all: $(NAME)

run: all
	ARG="2 1 5 4 3"; ./$(NAME) $$ARG
$(NAME): $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re