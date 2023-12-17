CC = gcc
CFLAGS = -Wall -Wextra -Werror
BINDIR = ./bin
INCDIR = ./inc
SRCDIR = ./src
NAME = push_swap
HEADER = $(INCDIR)/push_swap.h
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS))
LIBFT = ./libft/libft.a

all: $(NAME)

run: all
	ARG="2 1 5 4 3"; ./$(NAME) $$ARG

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -I$(INCDIR) $(OBJS) $(LIBFT) -o $(NAME)

$(BINDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@$(CC) -I$(INCDIR) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re