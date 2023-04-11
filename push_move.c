/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:15:00 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/11 12:16:16 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdlib.h>

void	pa(t_stack *s1, t_stack *s2)// coge el primer elemento de B y lo pone en primera posicion de A
{
	t_elem	*temp;

	if (s2->size == 0) // si no hay nada en B no queremos que haga nada
		return;
	temp = s2->first; //primero de todo guaardamos en temp el 1r elemento de B
	s2->first = s2->first->next; // hacemos que en el puntero del 1r elemento de B senale al 2o
	temp->next = s1->first; // hacemos que temp senale a next (que aun no hay nada)
	s1->first = temp; // finalmente adjudicamos a temp la priemra posicion y como previamente hemos hecho que temp senale al siguiente esta todo hehco
	s1->size += 1;
	s2->size -= 1;
	printf("pa\n");
}

void	pb(t_stack *s1, t_stack *s2) // coge el primer elemento de A y lo pone en primera posicion de B
{
	t_elem	*temp;

	if(s1->size == 0)
		return;
	temp = s1->first;
	s1->first = s1->first->next;
	temp->next = s2->first;
	s2->first = temp;
	s1->size -= 1;
	s2->size += 1;
	printf("pb\n");
}
