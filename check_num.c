/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:49:43 by mehernan          #+#    #+#             */
/*   Updated: 2023/02/07 18:02:51 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "impl_stack.h"
#include <stdio.h>

int	check_num(char *c[])
{
	int	i;
	int	j;

	i = 1;
	while (c[i] != NULL)
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
int	check_int(char *c[])//result = result * 10 + str[x]
{
	long check;
	int count;
	int i;

	check = 0;
	i = 1;
	while (c[i] != NULL)
	{
		count = 0;
		while (c[i][count] != 0)
		{
			if(ft_strlen(c[i]) > 11)//para controlar si es mas largo de 11
				return (0);
			check = (check * 10) + (c[i][count] - '0');//para que sea int
			if(check > 2147483647 || check < -2147483648)
				return (0);
			count++;
		}
		i++;
	}
	return (1);
}
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
