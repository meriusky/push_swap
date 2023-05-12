/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:23:03 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:16:50 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *s1)
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if (s1->size < 2)
		return ;
	temp = s1->first;
	penultimate_elem = get_penultimate_elem(s1);
	s1->first = penultimate_elem->next;
	s1->first->next = temp;
	penultimate_elem->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *s2)
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if (s2->size < 2)
		return ;
	temp = s2->first;
	penultimate_elem = get_penultimate_elem(s2);
	s2->first = penultimate_elem->next;
	s2->first->next = temp;
	penultimate_elem->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *s1, t_stack *s2)
{
	rra(s1);
	rrb(s2);
}
