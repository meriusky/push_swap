/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:16:58 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/11 12:22:53 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdlib.h>

void	ra(t_stack *s1) //sube todos los numeros una posicioon y el primero lo pone el ultimo
{
	t_elem	*temp; //temp de temporal
	t_elem	*penultimate_elem;

	if (s1->size < 2)
		return;
	temp = s1->first;
	penultimate_elem = get_penultimate_elem(s1);
	s1->first = s1->first->next; //la primera caja ahora apunta a la segunda
	penultimate_elem->next->next = temp; // temp debe ser el ultimo
	penultimate_elem->next->next->next = NULL; // y ahora anadimos al ultimo de todo null
	printf("ra\n");
}

void	rb(t_stack *s2)
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if(s2->size < 2)
		return;
	temp = s2->first;
	penultimate_elem = get_penultimate_elem(s2);
	s2->first = s2->first->next;
	penultimate_elem->next->next = temp;
	penultimate_elem->next->next->next = NULL;
	printf("rb\n");
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
