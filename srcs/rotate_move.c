/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:16:58 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:19:35 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *s1)
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if (s1->size < 2)
		return ;
	temp = s1->first;
	penultimate_elem = get_penultimate_elem(s1);
	s1->first = s1->first->next;
	penultimate_elem->next->next = temp;
	penultimate_elem->next->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *s2)
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if (s2->size < 2)
		return ;
	temp = s2->first;
	penultimate_elem = get_penultimate_elem(s2);
	s2->first = s2->first->next;
	penultimate_elem->next->next = temp;
	penultimate_elem->next->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack *s1, t_stack *s2)
{
	ra(s1);
	rb(s2);
}

t_elem	*get_penultimate_elem(t_stack *s)
{
	t_elem	*elem;

	if (s->size < 2)
		return (NULL);
	elem = s->first;
	while (elem != NULL)
	{
		if (elem->next->next == NULL)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
