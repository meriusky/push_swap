/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:15:51 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/17 19:22:12 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	if (check_num(argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_int(argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_dplnum(argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*s2;
	t_stack	*b;

	if (!check_errors(argc, argv))
		return (0);
	i = 1;
	s2 = init_stack();
	b = init_stack();
	while (argv[i] != NULL)
	{
		push(s2, converter(argv[i]));
		i++;
	}
	if (!sorted_check(argc, &s2, &b))
		return (0);
	ft_free(&s2);
	ft_free(&b);
}
