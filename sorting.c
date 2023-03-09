/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:41:15 by mehernan          #+#    #+#             */
/*   Updated: 2023/03/09 17:50:14 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdio.h>

//la info de aqui devera relacionarse directamente con la info de impl_stac.c y de ahi mover cosas
//funcion para ordenar la stack llamando a funciones con movimientos
//hay que ordenar con las stacks

//recordamos que al poner un & a la v ariable que mandamos y anadir un * de mas, en este caso ya era un puntero por lo tanto, doble puntero.
int	sorted_check(int argc, t_stack **s2, t_stack **b)
{
	t_elem	*tmp;

	tmp = (*s2)->first;// indicamos que temp es la 1a posicion de la stack
	while(tmp->next != NULL && tmp->value < tmp->next->value)
		tmp = tmp->next;//para que siga adelnte el while
	if (tmp->next == NULL)
		return (0);
//si no cumpe las condiciones para estar ordenado, se va a ser ordenado
	sorting(argc, s2, b);
	return (1);
}
void	sorting(int argc, t_stack **s2, t_stack **b)
{
	if(argc - 1 == 2)
		*s2 = two_num(*s2);
	if(argc - 1 == 3)
		*s2 = three_num(*s2);
	if(argc - 1 == 4)
		*s2 = four_num(*s2, *b);
	if(argc - 1 == 5)
		*s2 = five_num(*s2, *b);
	if(argc - 1 == 6)
		*s2 = sort_more_than_five(*s2, *b)// quizas hay que pasat argc
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
		if(p2->value > p3->value)
		{
			sa(s2);
			ra(s2);
		}
		else
			return(s2);
	}
	else
		s2 = three_num_2ndpart(s2, p1, p2, p3);
	return (s2);
}
t_stack	*three_num_2ndpart(t_stack *s2, t_elem *p1, t_elem *p2, t_elem *p3)
{
	 if(p2->value < p1->value && p2->value < p3->value)
	{
		if(p1->value < p3->value)
			sa(s2);
		else
			ra(s2);
	}
	else if (p1->value < p2->value)
		rra(s2);
		else
		{
			sa(s2);
			rra(s2);
		}
	return(s2);
}
t_stack		*four_num(t_stack *s2, t_stack *b)//busco el pequeno y lo paso a una stack b
{
	t_elem *p1;
	t_elem *p2;
	t_elem *p3;
	t_elem *p4;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	p4 = s2->first->next->next->next;

	if(p1->value < p2->value && p1->value < p3->value && p1->value < p4->value)
		pb(s2, b);
	else if(p2->value < p1->value && p2->value < p3->value && p2->value < p4->value) 
	{
		sa(s2);
		pb(s2, b);
	}
	else
		s2 = four_num_2ndpart(s2, b);
	s2 = three_num(s2);
	pa(s2, b);
	return(s2);
}
t_stack		*four_num_2ndpart(t_stack *s2, t_stack *b)
{
	t_elem *p1;
	t_elem *p2;
	t_elem *p3;
	t_elem *p4;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	p4 = s2->first->next->next->next;
	if(p3->value < p1->value && p3->value < p2->value && p3->value < p4->value)
	{
		rra(s2);
		rra(s2);
		pb(s2, b);
	}
	else
	{
		rra(s2);
		pb(s2, b);
	}
	s2 = three_num(s2);
	pa(s2, b);
	return(s2);
}
t_stack		*five_num(t_stack *s2, t_stack *b)
{
	t_elem *p1;
	t_elem *p2;
	t_elem *p3;
	t_elem *p4;
	t_elem *p5;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	p4 = s2->first->next->next->next;
	p5 = s2->first->next->next->next->next;
	if(p1->value < p2->value && p1->value < p3->value && p1->value < p4->value && p1->value < p5->value)
		pb(s2, b);
	else if(p2->value < p1->value && p2->value < p3->value && p2->value < p4->value && p2->value < p5->value)
	{
		sa(s2);
		pb(s2, b);
	}
	else
		s2 = five_num_2ndpart(s2, b);
	s2 = four_num(s2, b);
	pa(s2, b);
	return(s2);
}
t_stack		*five_num_2ndpart(t_stack *s2, t_stack *b)
{
	t_elem *p1;
	t_elem *p2;
	t_elem *p3;
	t_elem *p4;
	t_elem *p5;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	p4 = s2->first->next->next->next;
	p5 = s2->first->next->next->next->next;
	if(p3->value < p1->value && p3->value < p2->value && p3->value < p4->value && p3->value < p5->value)
	{
		ra(s2);
		ra(s2);
		pb(s2, b);
	}
	else
		s2 = five_num_3rdpart(s2, b);
	s2 = four_num(s2, b);
	pa(s2, b);
	return(s2);
}
t_stack		*five_num_3rdpart(t_stack *s2, t_stack *b)
{
	t_elem *p1;
	t_elem *p2;
	t_elem *p3;
	t_elem *p4;
	t_elem *p5;

	p1 = s2->first;
	p2 = s2->first->next;
	p3 = s2->first->next->next;
	p4 = s2->first->next->next->next;
	p5 = s2->first->next->next->next->next;
	 if(p4->value < p1->value && p4->value < p2->value && p4->value < p3->value && p4->value < p5->value)
	{
		rra(s2);
		rra(s2);
		pb(s2, b);
	}
	else
	{
		rra(s2);
		pb(s2, b);
	}
	s2 = four_num(s2, b);
	pa(s2, b);
	return(s2);
}
