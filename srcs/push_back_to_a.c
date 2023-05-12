/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:32:30 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/15 16:53:57 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a_2ndpart(t_stack **s2, t_stack **b, t_elem **tmpb, int *c)
{
	if (*c == 1)
	{
		pa(*s2, *b);
		*tmpb = (*b)->first;
	}
	else
	{
		if (*c <= (((*b)->size) / 2))
			rb(*b);
		else
			rrb(*b);
		*tmpb = (*b)->first;
		*c = 1;
	}
}

void	push_back_to_a_3rdpart(t_stack **s2, t_stack **b, t_elem **tmpb, int *a)
{
	if (a[1] == 1)
	{
		pa(*s2, *b);
		sa(*s2);
		*tmpb = (*b)->first;
		a[0] = 0;
	}
	else
	{
		if (a[1] <= (((*b)->size) / 2))
			rb(*b);
		else
			rrb(*b);
		*tmpb = (*b)->first;
		a[1] = 1;
	}
}

void	push_back_to_a_4thpart(t_elem **tmpb, int *c)
{
	*tmpb = (*tmpb)->next;
	*c = *c + 1;
}

void	push_back_to_a(t_stack **s2, t_stack **b)
{
	t_elem	*tmpb;
	int		arr[2];

	tmpb = (*b)->first;
	arr[0] = 0;
	arr[1] = 1;
	while ((*b)->size)
	{
		if ((*b)->first->position == ((*b)->size - 1) && arr[0] == 0)
		{
			pa(*s2, *b);
			arr[0] = 1;
			tmpb = (*b)->first;
		}
		else
		{
			if (tmpb->position == (*b)->size && arr[0] == 0)
				push_back_to_a_2ndpart(s2, b, &tmpb, &arr[1]);
			else if (tmpb->position == ((*b)->size + 1) && arr[0] == 1)
				push_back_to_a_3rdpart(s2, b, &tmpb, arr);
			else
				push_back_to_a_4thpart(&tmpb, &arr[1]);
		}
	}
}
