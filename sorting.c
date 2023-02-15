/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:41:15 by mehernan          #+#    #+#             */
/*   Updated: 2023/02/15 19:56:20 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdio.h>

//la info de aqui devera relacionarse directamente con la info de impl_stac.c y de ahi mover cosas
//funcion para ver si la stack esta ordenada o no (en realidad no hace falta tanto)
//hay que ordenar con las stacks

//recordamos que al poner un & a la v ariable que mandamos y anadir un * de mas, en este caso ya era un puntero por lo tanto, doble puntero.
int	sorted_check(int argc, t_stack **s2)
{
	t_elem	*tmp;

	tmp = (*s2)->first;// indicamos que temp es la 1a posicion de la stack
	while(tmp->next != NULL && tmp->value < tmp->next->value)
		tmp = tmp->next;//para que siga adelnte el while
	if (tmp->next == NULL)
		return (0);
//si no cumpe las condiciones para estar ordenado, se va a ser ordenado
	sorting(argc, s2);
	return (1);
}
void	sorting(int argc, t_stack **s2)
{
	if(argc - 1 == 2)
		*s2 = two_num(*s2);
	if(argc - 1 == 3)
		*s2 = three_num(*s2);
/*	if(argc - 1 == 4)
		four_num(s2);
	if(argc - 1 == 5)
		five_num(s2);
*/
}
t_stack		*two_num(t_stack *s2)
{
	sa(s2);
	return(s2);
}
t_stack		*three_num(t_stack *s2)
{
	t_elem	*p1;
	t_elem	*p2;
	t_elem	*p3;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	if(p1->value < p2->value && p1->value < p3->value)
	{
		sa(s2);
		ra(s2);
	}
	else if(p2->value < p1->value && p2->value < p3->value)
	{
		if(p1->value < p3->value)
			sa(s2);
		else
			ra(s2);
	}
	else
		s2 = lastp_little(s2, p1, p2);
	return (s2);
}
t_stack	*lastp_little(t_stack *s2, t_elem *p1, t_elem *p2)
{
	if (p1->value < p2->value)
			rra(s2);
		else
		{
			sa(s2);
			rra(s2);
		}
	return(s2);
}
