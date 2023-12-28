# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:42:03 by momrane           #+#    #+#              #
#    Updated: 2023/12/28 14:06:01 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
BINDIR = ./bin
INCDIR = ./inc
SRCDIR = ./src
NAME = push_swap
HEADER = $(INCDIR)/push_swap.h
SRCDIRS = $(SRCDIR) $(SRCDIR)/errors $(SRCDIR)/init $(SRCDIR)/instructions $(SRCDIR)/stacks
SRCS = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))
OBJS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS))
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

clean:
	rm -rf $(BINDIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re