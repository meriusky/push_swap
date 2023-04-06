/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:26:25 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/06 19:29:45 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"

// This file contains the algoridm that orders the quantity greater that five numbers.
// Dividir la stack A en 3 grupos de mas pequenos a mas grandes
// Llevar cada grupo a la stack b
// Llevar de vuelta todos los numeros a la stack uno por uno de mayor a menor

void	six_to_hundred(t_stack **s2, t_stack **b)
{
	int		pos;//posicion real de los umeros que se va rcorriendo
	int		size;//size fijo de la stack
	int		group;//valor para comparar la position, cantidad de numeos en la qu se divide un grupo
	int		count;//numero de numeros pasados con pb
	t_elem	*temp;//variable temporal primer elemento de s2(A)

	pos = 0;
	temp = (*s2)->first;
	size = (*s2)->size;
	group = ((*s2)->size / 3);
	count = 0; 
	while((*s2)->size != 0)//mientras el tamano de size no sea zero
	{
		if (temp->position <= group)// posicion de temp es mas pequena o igual que grup,es que esta dentro de lo que queremos coger
		{
			if (pos == 0)
			{
				pb(*s2, *b);
				if (temp->position > (group - (size / 3)) && temp->position <= (group - (size / 3 / 2)))
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
			group = group + (size / 3);
	}
	push_back_to_A(s2, b);
//	print_stack(s2);
//	print_stack(b);
}
void	push_back_to_A(t_stack **s2, t_stack **b)
{
	t_elem	*tempb; //variable temporal sobre el primer elemento de B
	int		flag;
	int		count;

	tempb = (*b)->first;
	flag = 0;
	count = 1;// es uno, ya que en un futuro lo usaremoos para saber si un num sta a la mitad y al dividir, 0 n se cuenta como num
	while ((*b)->size)
	{
		if((*b)->first->position == ((*b)->size - 1) && flag == 0)
		{
			pa(*s2, *b);
			flag = 1;
			tempb = (*b)->first;
		}
		else
		{
			if(tempb->position == (*b)->size && flag == 0)//no estoy segura si dejar solo el tempb o tempb->value
			{
				if(count == 1)
				{
					pa(*s2, *b);
					tempb = (*b)->first;
					count = 1;
				}
				else
				{
					if(count <= (((*b)->size) / 2))
						rb(*b);
					else
						rrb(*b);
					tempb = (*b)->first;
					count = 1;
				}
			}
			else if (tempb->position == ((*b)->size + 1) && flag == 1)
			{
				if(count == 1)
				{
					pa(*s2, *b);
					sa(*s2);
					tempb = (*b)->first;
					flag = 0;
					count = 1;
				}
				else
				{
					if(count <= (((*b)->size) / 2))
						rb(*b);
					else
						rrb(*b);
					tempb = (*b)->first;
					count = 1;
				}
			}
			else
			{
				tempb = tempb->next;
				count++;
			}
		}
	}
}

//Buscar el numero mas pequeno y darle 1 de posicion
//seguir asi adelante
// 
void	give_position(t_stack **s2)//ns si esta bien
{
	int		position;// posicion que le asignaremos
	t_elem	*temp;//la posicion en la que estamos y vamos comparando el valor con el del resto
	t_elem	*count;//el resto de posiciones que comparamos con temp

	temp = (*s2)->first;//temp es la primera posicion de la stack
	position = 1;//la posicion actual que comparamos
	count = temp->next;
	while (temp != NULL) //&& temp->value )//mientras no se acaba la stack que vaya pasando de posicion
	{
		while (temp != NULL && temp->position != 0)//comparamos con 0 para que temp no sea ninguno de los que ya hemos guardado que son mas pequeno, ya que temp ha sido previamnte guardado con una posicion para poder seguir al siguiente
			temp = temp->next;
		if (temp == NULL)
			break ;//si es null sale del while grande y se acabo
		while (temp->value < count->value && count->next != NULL)//valor de temp  mas pequena que count, que siga comparando
			count = count->next;
		if (count->next == NULL)//si temp ya es el mas pequeno y no se puede comparar pq se acaba la stack
		{
			give_position_2nd(s2, &count, &temp, &position);//como no cabia lopaso aqui
			continue ;
		}
		give_position_3rd(&count, &temp);
	}
}
void	give_position_2nd(t_stack **s2, t_elem **count, t_elem **temp, int *pos)
{
	if ((*temp)->value > (*count)->value && (*count)->position == 0)//si temp es mayor al valor del que se compara i la posicion de este es 0, es decir que no se ha guardado aun, que se guarde ya que eso quiere decir que el ultimo de la estac es mas pequeno que el actual temp asi que le damos una posicion a count
	{
		(*count)->position = *pos;
		*pos = *pos + 1;
	}
	else//si lo anterior no sucede pues hacemos lo mismo solo que guardando el teo en vez de el count
	{
		(*temp)->position = *pos;
		*pos = *pos + 1;// que sea +1 hace que cada posicion que se adjunta sea superior a la anterioir
		(*temp) = (*s2)->first;
		(*count) = (*temp)->next;
		//continue ;//para que vuelva a empezar en while desde el principio
	}
}
void	give_position_3rd(t_elem **count, t_elem **temp)
{
	if ((*count)->position != 0)// si se da el caso que count ya ha sido guardado no debemos comparar temp con ese asi que avanzamos el count al siguiente
		(*count) = (*count)->next;
	else
	{
		(*temp) = (*count);//si no entra, el valor de count es menor, asi que temp sea count mejor que dar vueltas xd
		(*count) = (*temp)->next;
	}
}
