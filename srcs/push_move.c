/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:15:00 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:19:30 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *s1, t_stack *s2)
{
	t_elem	*temp;

	if (s2->size == 0)
		return ;
	temp = s2->first;
	s2->first = s2->first->next;
	temp->next = s1->first;
	s1->first = temp;
	s1->size += 1;
	s2->size -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *s1, t_stack *s2)
{
	t_elem	*temp;

	if (s1->size == 0)
		return ;
	temp = s1->first;
	s1->first = s1->first->next;
	temp->next = s2->first;
	s2->first = temp;
	s1->size -= 1;
	s2->size += 1;
	write(1, "pb\n", 3);
}
