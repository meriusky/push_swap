/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:49:43 by mehernan          #+#    #+#             */
/*   Updated: 2023/01/27 19:20:27 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "impl_stack.h"
#include <stdio.h>

int	check_num(char *c[])
{
	int	i;
	int	j;

	i = 1;
	while (c[i] != 0)
	{
		j = 0;
		while (c[i][j] != 0)
		{
			if (c[i][j] < '0' || c[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
