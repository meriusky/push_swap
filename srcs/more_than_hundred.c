/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:06:47 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:19:04 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	more_than_hundred_2ndpart(t_stack **s2, t_stack **b, t_elem **tmp, int *arr)
{
	pb(*s2, *b);
	if ((*tmp)->position > (arr[3] - (arr[2] / 5)) \
		&& (*tmp)->position <= (arr[3] - (arr[2] / 5 / 2)))
		rb(*b);
	return (arr[1] + 1);
}

int	more_than_hundred_3rdpart(t_stack **s2, t_elem **tmp, int *arr)
{
	if (arr[0] <= (*s2)->size / 2)
		ra(*s2);
	else
		rra(*s2);
	(*tmp) = (*s2)->first;
	return (0);
}

void	more_than_hundred(t_stack **s2, t_stack **b)
{
	int		arr[4];
	t_elem	*tmp;

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = (*s2)->size;
	arr[3] = ((*s2)->size / 5);
	tmp = (*s2)->first;
	while ((*s2)->size != 0)
	{
		if (tmp->position <= arr[3])
		{
			if (arr[0] == 0)
				arr[1] = more_than_hundred_2ndpart(s2, b, &tmp, arr);
			arr[0] = more_than_hundred_3rdpart(s2, &tmp, arr);
		}
		else
		{
			tmp = tmp->next;
			arr[0]++;
		}
		if (arr[1] == arr[3])
			arr[3] = arr[3] + (arr[2] / 5);
	}
	push_back_to_a(s2, b);
}
