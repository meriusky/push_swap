/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:23:03 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/11 12:24:58 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdlib.h>

void	rra(t_stack *s1) //rota el ultimo y lo pone arriba
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if (s1->size < 2)
		return;
	temp = s1->first;
	penultimate_elem = get_penultimate_elem(s1);
	s1->first = penultimate_elem->next;
	s1->first->next = temp;
	penultimate_elem->next = NULL;
	printf("rra\n");
}

void	rrb(t_stack *s2)
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if (s2->size < 2)
		return;
	temp = s2->first;
	penultimate_elem = get_penultimate_elem(s2);
	s2->first = penultimate_elem->next;
	s2->first->next = temp;
	penultimate_elem->next = NULL;
	printf("rrb\n");
}

void	rrr(t_stack *s1, t_stack *s2)
{
	rra(s1);
	rrb(s2);
}
