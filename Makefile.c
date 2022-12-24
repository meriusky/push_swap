/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:53:50 by mehernan          #+#    #+#             */
/*   Updated: 2022/12/24 16:12:45 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = //IDK

CC = gcc

SRCS = push_swap.c

OBJS = $(SRCS:.c=.d)//norminette dice que hay un error en el $, (unrecognized token)

CFLAGS = -Wall -Werror -Wextra //-MMD -MP

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

.PHONY: all clean fclean re
