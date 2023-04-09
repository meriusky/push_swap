# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 19:17:52 by mehernan          #+#    #+#              #
#    Updated: 2023/04/09 19:54:31 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

SRCS = impl_stack.c main.c check_num.c converter.c sorting.c sort_six_to_hundred.c more_than_hundred.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -MMD -MP

DEPS = $(SRCS:.c=.d)

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
