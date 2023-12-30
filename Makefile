# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:42:03 by momrane           #+#    #+#              #
#    Updated: 2023/12/30 15:28:54 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = 				gcc
CFLAGS =			-Wall -Wextra -Werror

BINDIR =			./bin
INCDIR =			./inc
SRCDIR = 			./src
ALGO_DIR = 			$(SRCDIR)/algo
CHECKER_DIR =		$(SRCDIR)/checker
ERRORS_DIR =		$(SRCDIR)/errors
INIT_DIR =			$(SRCDIR)/init
INSTRUCTIONS_DIR =	$(SRCDIR)/instructions

HEADER = 			$(INCDIR)/push_swap.h
LIBFT =				./libft/libft.a

NAME =				push_swap
CHECKER = 			checker

ALGO_SRCS =			$(ALGO_DIR)/ft_create_stack.c $(ALGO_DIR)/ft_little_sort.c \
					$(ALGO_DIR)/ft_stack_utils.c $(ALGO_DIR)/ft_stack_utils2.c \
					$(ALGO_DIR)/ft_turk_sort.c
CHECKER_SRCS =		$(CHECKER_DIR)/checker_bonus.c $(CHECKER_DIR)/get_next_line_bonus.c \
					$(CHECKER_DIR)/get_next_line_utils_bonus.c \
					$(CHECKER_DIR)/instructions_bonus.c $(CHECKER_DIR)/ft_checker_error_bonus.c
ERRORS_SRCS =		$(ERRORS_DIR)/ft_args_error.c $(ERRORS_DIR)/ft_create_stack_error.c \
					$(ERRORS_DIR)/ft_duplicate_error.c \
					$(ERRORS_DIR)/ft_new_node_error.c $(ERRORS_DIR)/ft_print_error.c
INIT_SRCS =			$(INIT_DIR)/ft_check_args.c $(INIT_DIR)/ft_init_a_nodes.c \
					$(INIT_DIR)/ft_init_b_nodes.c $(INIT_DIR)/ft_init_utils.c
INSTRUCTIONS_SRCS =	$(INSTRUCTIONS_DIR)/ft_push.c $(INSTRUCTIONS_DIR)/ft_rotate.c \
					$(INSTRUCTIONS_DIR)/ft_reverse_rotate.c $(INSTRUCTIONS_DIR)/ft_swap.c

SRCS =				$(ALGO_SRCS) $(ERRORS_SRCS) $(INIT_SRCS) \
					$(INSTRUCTIONS_SRCS) $(SRCDIR)/push_swap.c
SRCS_BONUS =		$(ALGO_SRCS) $(ERRORS_SRCS) \
					$(INIT_SRCS) $(INSTRUCTIONS_SRCS) \
					$(CHECKER_SRCS)

OBJS =				$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS))
OBJS_BONUS =		$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS_BONUS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -I$(INCDIR) $(OBJS) $(LIBFT) -o $(NAME)

$(BINDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) -I$(INCDIR) -c $< -o $@

$(LIBFT):
	make -C ./libft

bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) -I$(INCDIR) $(OBJS_BONUS) $(LIBFT) -o $(CHECKER)

clean:
	rm -rf $(BINDIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re