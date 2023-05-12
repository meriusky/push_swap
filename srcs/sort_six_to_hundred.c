/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_to_hudred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:26:25 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:17:19 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	six_to_hundred_2ndpart(t_stack **s2, t_stack **b, t_elem **temp, int *arr)
{
	pb(*s2, *b);
	if ((*temp)->position > (arr[3] - (arr[2] / 3)) \
		&& (*temp)->position <= (arr[3] - (arr[2] / 3 / 2)))
		rb(*b);
	return (arr[1] + 1);
}

int	six_to_hundred_3rdpart(t_stack **s2, t_elem **temp, int *arr)
{
	if (arr[0] <= (*s2)->size / 2)
		ra(*s2);
	else
		rra(*s2);
	(*temp) = (*s2)->first;
	return (0);
}

void	six_to_hundred(t_stack **s2, t_stack **b)
{
	int		arr[4];
	t_elem	*temp;

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = (*s2)->size;
	arr[3] = ((*s2)->size / 3);
	temp = (*s2)->first;
	while ((*s2)->size != 0)
	{
		if (temp->position <= arr[3])
		{
			if (arr[0] == 0)
				arr[1] = six_to_hundred_2ndpart(s2, b, &temp, arr);
			arr[0] = six_to_hundred_3rdpart(s2, &temp, arr);
		}
		else
		{
			temp = temp->next;
			arr[0]++;
		}
		if (arr[1] == arr[3])
			arr[3] = arr[3] + (arr[2] / 3);
	}
	push_back_to_a(s2, b);
}
