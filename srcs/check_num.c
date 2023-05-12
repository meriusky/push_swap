/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:49:43 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:17:58 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			{
				if (j == 0 && c[i][j] == 45 && c[i][j + 1] != '\0')
				{
					j++;
					continue ;
				}
				return (0);
			}
			j++;
		}
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_dplnum(char *c[])
{
	int	i;
	int	j;

	i = 1;
	while (c[i] != NULL)
	{
		j = i + 1;
		while (c[j] != NULL)
		{
			if (ft_atoi(c[i]) == ft_atoi(c[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char *c[])
{
	long	check;
	int		count;
	int		i;

	i = 1;
	while (c[i] != NULL)
	{
		check = 0;
		count = 0;
		while (c[i][count] != 0)
		{
			if (ft_strlen(c[i]) > 11)
				return (0);
			check = (check * 10) + (c[i][count] - '0');
			if (check > 2147483647 || check < -2147483648)
				return (0);
			count++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	count;
	int	num;
	int	sign;

	count = 0;
	num = 0;
	sign = 1;
	while (str[count] == '\t' || str[count] == '\f' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == ' ')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = (num * 10) + (str[count] - '0');
		count++;
	}
	return (num * sign);
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
