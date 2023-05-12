/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_and_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:33:52 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:17:04 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*four_num(t_stack *s2, t_stack *b)
{
	t_elem	*p1;
	t_elem	*p2;
	t_elem	*p3;
	t_elem	*p4;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	p4 = s2->first->next->next->next;
	if (p1->value < p2->value && p1->value < p3->value && p1->value < p4->value)
		pb(s2, b);
	else if (p2->value < p1->value && p2->value < p3->value \
		&& p2->value < p4->value)
	{
		sa(s2);
		pb(s2, b);
	}
	else
		s2 = four_num_2ndpart(s2, b);
	s2 = three_num(s2);
	pa(s2, b);
	return (s2);
}

t_stack	*four_num_2ndpart(t_stack *s2, t_stack *b)
{
	t_elem	*p1;
	t_elem	*p2;
	t_elem	*p3;
	t_elem	*p4;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	p4 = s2->first->next->next->next;
	if (p3->value < p1->value && p3->value < p2->value \
		&& p3->value < p4->value)
	{
		rra(s2);
		rra(s2);
		pb(s2, b);
	}
	else
	{
		rra(s2);
		pb(s2, b);
	}
	s2 = three_num(s2);
	pa(s2, b);
	return (s2);
}

t_stack	*five_num(t_stack *s2, t_stack *b)
{
	t_elem	*p[5];

	p[0] = s2->first;
	p[1] = s2->first->next;
	p[2] = s2->first->next->next;
	p[3] = s2->first->next->next->next;
	p[4] = s2->first->next->next->next->next;
	if (p[0]->value < p[1]->value && p[0]->value < p[2]->value \
		&& p[0]->value < p[3]->value && p[0]->value < p[4]->value)
		pb(s2, b);
	else if (p[1]->value < p[0]->value && p[1]->value < p[2]->value \
		&& p[1]->value < p[3]->value && p[1]->value < p[4]->value)
	{
		sa(s2);
		pb(s2, b);
	}
	else
		s2 = five_num_2ndpart(s2, b, p);
	s2 = four_num(s2, b);
	pa(s2, b);
	return (s2);
}

t_stack	*five_num_2ndpart(t_stack *s2, t_stack *b, t_elem **p)
{
	if (p[2]->value < p[0]->value && p[2]->value < p[1]->value \
		&& p[2]->value < p[3]->value && p[2]->value < p[4]->value)
	{
		ra(s2);
		ra(s2);
		pb(s2, b);
	}
	else
		s2 = five_num_3rdpart(s2, b, p);
	return (s2);
}

t_stack	*five_num_3rdpart(t_stack *s2, t_stack *b, t_elem **p)
{
	if (p[3]->value < p[0]->value && p[3]->value < p[1]->value \
		&& p[3]->value < p[2]->value && p[3]->value < p[4]->value)
	{
		rra(s2);
		rra(s2);
		pb(s2, b);
	}
	else
	{
		rra(s2);
		pb(s2, b);
	}
	return (s2);
}
