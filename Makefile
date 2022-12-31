# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 19:17:52 by mehernan          #+#    #+#              #
#    Updated: 2022/12/31 19:38:57 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap

CC = gcc

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -MMD -MP

DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
