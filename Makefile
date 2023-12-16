CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJDIR = objs
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
NAME = push_swap

all: $(NAME)

run: all
	ARG="1 2 4 3 5 6"; ./$(NAME) $$ARG
$(NAME): $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re