# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:29:15 by fleduc            #+#    #+#              #
#    Updated: 2022/05/23 14:50:13 by fleduc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = push_swap.c errors.c ops1.c ops2.c both_ops.c small.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean:
	@$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re all

.SILENT: fclean clean re all $(NAME) $(OBJS)
