# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:29:15 by fleduc            #+#    #+#              #
#    Updated: 2022/06/07 15:36:35 by fleduc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

SRCS = srcs/push_swap.c srcs/errors.c srcs/ops1.c srcs/ops2.c srcs/both_ops.c \
		srcs/small.c srcs/utils1.c srcs/utils2.c srcs/big.c

SRCS_BONUS = bonus/main_bonus.c bonus/errors_bonus.c bonus/utils1_bonus.c \
		bonus/ops1_bonus.c bonus/ops2_bonus.c bonus/both_ops_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

bonus: $(OBJS_BONUS)
	@$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a -o $(NAME_BONUS)

clean:
	@$(MAKE) -C libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) -C libft fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: fclean clean re all

.SILENT: fclean clean re all bonus $(NAME) $(OBJS) $(NAME_BONUS) $(OBJS_BONUS)
