# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 19:17:52 by mehernan          #+#    #+#              #
#    Updated: 2023/04/14 13:32:10 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

SRCS = $(addprefix $(SRCS_DIR)/, impl_stack.c swap_move.c push_move.c rotate_move.c rotate_reverse_move.c \
	   main.c check_num.c converter.c sorting.c sort_four_and_five.c \
	   sort_six_to_hundred.c more_than_hundred.c push_back_to_a.c give_position.c ft_free.c)

INC_DIR = inc
SRCS_DIR = srcs

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CFLAGS = -Wall -Werror -Wextra -MMD -MP -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
