# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liulm <liulm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:58:17 by liulm             #+#    #+#              #
#    Updated: 2025/01/06 15:36:12 by liulm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS =	\

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

all: $(NAME)



clean:
		rm -f $(OBJS)
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./ft_printf fclean

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
