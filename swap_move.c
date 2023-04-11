/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:13:08 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/11 12:48:49 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdlib.h>

void	sa(t_stack *s1) //swap, intercambia los dos primeros elementos de A
{
	t_elem	*temp;
	t_elem	*third;

	if (s1->size < 2) // no puede ser menor que 2 porque no puedes swap un elemento solo o 0
		return;
	temp = s1->first; //temp ahora senala a first
	third = s1->first->next->next;
	s1->first = s1->first->next; //s1 first y s2 first apuntan al mismo sitio
	s1->first->next = temp; // el segundo elemmento es temp
	s1->first->next->next = third; //el tercer elemento es third (la 3a caja)
	// s1->first = 57
	// s2->first = 46
	// temp = s1->first
	// temp = 57
	// s1->first = s2->first
	// s1->first = 46
	// s2->first = 46
	// s2->first = temp
	// s2->first = 57
//	temp = s1->first->next;
//	s1->first->next = s2->first->next;
//	s2->first->next = temp;
	printf("sa\n");
}

void	sb(t_stack *s2) // lo mismo que sa
{
	t_elem	*temp;
	t_elem	*third;

	if (s2->size < 2)
		return;
	temp = s2->first;
	third = s2->first->next->next;
	s2->first = s2->first->next;
	s2->first->next = temp;
	s2->first->next->next = third;
	printf("sb\n");
}

void	ss(t_stack *s1, t_stack *s2) //sa y sb a la vez
{
	sa(s1);
	sb(s2);
}
