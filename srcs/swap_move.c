/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:13:08 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/14 13:17:48 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s1)
{
	t_elem	*temp;
	t_elem	*third;

	if (s1->size < 2)
		return ;
	temp = s1->first;
	third = s1->first->next->next;
	s1->first = s1->first->next;
	s1->first->next = temp;
	s1->first->next->next = third;
	write(1, "sa\n", 3);
}

void	sb(t_stack *s2)
{
	t_elem	*temp;
	t_elem	*third;

	if (s2->size < 2)
		return ;
	temp = s2->first;
	third = s2->first->next->next;
	s2->first = s2->first->next;
	s2->first->next = temp;
	s2->first->next->next = third;
	write(1, "sb\n", 3);
}

void	ss(t_stack *s1, t_stack *s2)
{
	sa(s1);
	sb(s2);
}
