/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:44:55 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:18:43 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*save;

	save = malloc(sizeof(t_stack));
	if (!save)
		return (NULL);
	save->size = 0;
	save->first = NULL;
	return (save);
}

t_elem	*push(t_stack *s, int value)
{
	t_elem	*newelem;
	t_elem	*count;

	newelem = malloc(sizeof(t_elem));
	if (!newelem)
		return (NULL);
	newelem->next = NULL;
	newelem->value = value;
	newelem->position = 0;
	if (s->first == NULL)
		s->first = newelem;
	else
	{
		count = s->first;
		while (count->next != NULL)
		{
			count = count->next;
		}
		count->next = newelem;
	}
	s->size++;
	return (newelem);
}

void	pop(t_stack *s)
{
	t_elem	*first;

	first = s->first;
	s->first = first->next;
	free(first);
	s->size--;
}
