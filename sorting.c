/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:41:15 by mehernan          #+#    #+#             */
/*   Updated: 2023/02/14 19:25:10 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdio.h>

//la info de aqui devera relacionarse directamente con la info de impl_stac.c y de ahi mover cosas
//funcion para ver si la stack esta ordenada o no (en realidad no hace falta tanto)
//hay que ordenar con las stacks
int	sorted_check(int argc, t_stack **s2)
{
	t_elem	*tmp;

	tmp = (*s2)->first;
	while(tmp->next != NULL &&tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (0);
	sorting(argc, s2);
	return (1);
}
t_stack		**sorting(int argc, t_stack **s2)//esto creo que esta bien  es util
{
	if(argc - 1 == 2)
		*s2 = two_num(*s2);
/*	if(argc - 1 == 3)
		three_num(s2);
	if(argc - 1 == 4)
		four_num(s2);
	if(argc - 1 == 5)
		five_num(s2);*/
	return (s2);
}
t_stack		*two_num(t_stack *s2)//cambiar esto
{
	sa(s2);
	return(s2);
}
