/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:41:15 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:17:29 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_check(int argc, t_stack **s2, t_stack **b)
{
	t_elem	*tmp;

	tmp = (*s2)->first;
	while (tmp->next != NULL && tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (0);
	give_position(s2);
	sorting(argc, s2, b);
	return (1);
}

void	sorting(int argc, t_stack **s2, t_stack **b)
{
	if (argc - 1 == 2)
		*s2 = two_num(*s2);
	else if (argc - 1 == 3)
		*s2 = three_num(*s2);
	else if (argc - 1 == 4)
		*s2 = four_num(*s2, *b);
	else if (argc - 1 == 5)
		*s2 = five_num(*s2, *b);
	else if (argc - 1 > 5 && argc - 1 <= 100)
		six_to_hundred(s2, b);
	else
		more_than_hundred(s2, b);
}

t_stack	*two_num(t_stack *s2)
{
	sa(s2);
	return (s2);
}

t_stack	*three_num(t_stack *s2)
{
	t_elem	*p1;
	t_elem	*p2;
	t_elem	*p3;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	if (p1->value < p2->value && p1->value < p3->value)
	{
		if (p2->value > p3->value)
		{
			sa(s2);
			ra(s2);
		}
		else
			return (s2);
	}
	else
		s2 = three_num_2ndpart(s2, p1, p2, p3);
	return (s2);
}

t_stack	*three_num_2ndpart(t_stack *s2, t_elem *p1, t_elem *p2, t_elem *p3)
{
	if (p2->value < p1->value && p2->value < p3->value)
	{
		if (p1->value < p3->value)
			sa(s2);
		else
			ra(s2);
	}
	else if (p1->value < p2->value)
		rra(s2);
	else
	{
		sa(s2);
		rra(s2);
	}
	return (s2);
}
