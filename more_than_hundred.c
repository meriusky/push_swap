/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:06:47 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/10 13:49:23 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"

void	more_than_hundred(t_stack **s2, t_stack **b)
{
	int		pos;//posicion real de los numeros que se va recorriendo
	int		size;//size fijo de la stack
	int		group;//valor para comparar la position, cantidad de numeos en la qu se divide un grupo
	int		count;//numero de numeros pasados con pb
	t_elem	*temp;//variable temporal primer elemento de s2(A)

	pos = 0;
	temp = (*s2)->first;
	size = (*s2)->size;
	group = ((*s2)->size / 5);
	count = 0;
	while((*s2)->size != 0)//mientras el tamano de size no sea zero
	{
		if (temp->position <= group)// posicion de temp es mas pequena o igual que grup,es que esta dentro de lo que queremos coger
		{
			if (pos == 0)
			{
				pb(*s2, *b);
				if (temp->position > (group - (size / 5)) && temp->position <= (group - (size / 5 / 2)))
					rb(*b);//en caso de que temp position este abajo hay que moverlo a arriba para hacer pb y por lo tanto que se vayan colocando en Stack B
				count++;
			}
			if (pos <= (*s2)->size / 2)
				ra(*s2);//en caso de que pos no sea 0, que queremos qe sea 0 para hacer pb, haz ra para que ses pos 0
			else
				rra(*s2);// si lo primero no es pues rra porque estra abajo del todo
			temp = (*s2)->first;
			pos = 0;
		}
		else//todo esto para que cuando ya ha acabado la movida pasar a la siguiente posicion y seguir
		{
			temp = temp->next;
			pos++;
		}
		if (count == group)
			group = group + (size / 5);
	}
	push_back_to_A(s2, b);
//	print_stack(s2);
//	print_stack(b);
}
