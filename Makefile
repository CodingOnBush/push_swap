# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allblue <allblue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:42:03 by momrane           #+#    #+#              #
#    Updated: 2023/12/29 00:06:47 by allblue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
BINDIR = ./bin
INCDIR = ./inc
SRCDIR = ./src
NAME = push_swap
HEADER = $(INCDIR)/push_swap.h
SRCDIRS = $(SRCDIR)/errors $(SRCDIR)/init $(SRCDIR)/instructions $(SRCDIR)/stacks $(SRCDIR)
SRCDIRS_BONUS = $(SRCDIR)/errors $(SRCDIR)/init $(SRCDIR)/instructions $(SRCDIR)/stacks $(SRCDIR)/checker

SRCS = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))
SRCS_BONUS = $(foreach dir,$(SRCDIRS_BONUS),$(wildcard $(dir)/*.c))

OBJS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS))
OBJS_BONUS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS_BONUS))

LIBFT = ./libft/libft.a

all: $(NAME)

run: re
	ARG="1 5 4 7 -2 8 9"; ./push_swap $$ARG
$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -I$(INCDIR) $(OBJS) $(LIBFT) -o $(NAME)

$(BINDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(@D)  # Create the directory if it doesn't exist
	$(CC) -I$(INCDIR) -c $< -o $@

bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) -I$(INCDIR) $(OBJS_BONUS) $(LIBFT) -o checker

clean:
	rm -rf $(BINDIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re