# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liulm <liulm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 23:55:57 by lionelulm         #+#    #+#              #
#    Updated: 2025/02/11 15:12:20 by liulm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

HEADER = includes/push_swap.h

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address

RM		= rm -f

SRCS =	srcs/a_to_b.c				\
		srcs/b_to_a.c				\
		srcs/algorithm.c			\
		srcs/algorithm_utils.c		\
		srcs/algorithm_with_three.c	\
		srcs/check_errors.c			\
		srcs/initialize_stack.c		\
		srcs/main.c					\
		srcs/push.c					\
		srcs/rev_rotate.c			\
		srcs/rotate.c				\
		srcs/swap.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./utils/libft/libft.a

PRINTF = ./utils/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
		$(MAKE) -C ./utils/libft

$(PRINTF):
		$(MAKE) -C ./utils/ft_printf

clean:
		rm -f $(OBJS)
		$(MAKE) -C ./utils/libft fclean
		$(MAKE) -C ./utils/ft_printf fclean

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
