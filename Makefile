# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:42:03 by momrane           #+#    #+#              #
#    Updated: 2023/12/27 15:47:14 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
BINDIR = ./bin
INCDIR = ./inc
SRCDIR = ./src
NAME = push_swap
HEADER = $(INCDIR)/push_swap.h

# List of directories containing source files
SRCDIRS = $(SRCDIR) $(SRCDIR)/errors $(SRCDIR)/init $(SRCDIR)/instructions $(SRCDIR)/stacks

# Find all source files recursively in the source directories
SRCS = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))

# Generate the list of object files by replacing the source file directory with the binary directory
OBJS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS))
LIBFT = ./libft/libft.a

all: $(NAME)

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


# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# BINDIR = ./bin
# INCDIR = ./inc
# SRCDIR = ./src
# NAME = push_swap
# HEADER = $(INCDIR)/push_swap.h
# # SRCS =	$(SRCDIR)/errors/ft_exit_error.c $(SRCDIR)/errors/ft_print_error.c \
# # 		$(SRCDIR)/errors/handle_error.c $(SRCDIR)/init/ft_check_args.c \
# # 		$(SRCDIR)/init/ft_init_utils.c $(SRCDIR)/init/init_a_to_b.c \
# # 		$(SRCDIR)/init/init_b_to_a.c $(SRCDIR)/init/stack_init.c \
# # 		$(SRCDIR)/instructions/ft_push.c $(SRCDIR)/instructions/ft_rotate.c \
# # 		$(SRCDIR)/instructions/ft_reverse_rotate.c $(SRCDIR)/instructions/ft_swap.c \
# # 		$(SRCDIR)/stacks/ft_create_stack.c $(SRCDIR)/stacks/ft_print_stack.c \
# # 		$(SRCDIR)/stacks/ft_stack_utils.c $(SRCDIR)/stacks/ft_sort_stacks.c \
# # 		$(SRCDIR)/stacks/ft_sort_three.c $(SRCDIR)/push_swap.c

# SRCDIRS = $(SRCDIR)/errors $(SRCDIR)/init $(SRCDIR)/instructions $(SRCDIR)/stacks
# SRCS = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))
# OBJS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS))
# LIBFT = ./libft/libft.a

# all: $(NAME)

# $(LIBFT):
# 	make -C ./libft

# $(NAME): $(OBJS) $(LIBFT)
# 	$(CC) -I$(INCDIR) $(OBJS) $(LIBFT) -o $(NAME)

# $(BINDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
# 	$(CC) -I$(INCDIR) -c $< -o $@

# clean:
# 	rm -f $(OBJS)
# 	make clean -C ./libft

# fclean: clean
# 	rm -f $(NAME)
# 	make fclean -C ./libft

# re: fclean all

# .PHONY: all clean fclean re
