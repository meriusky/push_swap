/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_to_hudred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:26:25 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/12 18:58:27 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"

// This file contains the algoridm that orders the quantity greater that five numbers.
// Dividir la stack A en 3 grupos de mas pequenos a mas grandes
// Llevar cada grupo a la stack b
// Llevar de vuelta todos los numeros a la stack uno por uno de mayor a menor

// void	push_numbers_to_B(t_stack **s2, t_stack **b, t_elem *temp, int *arr);

int	six_to_hundred_2ndpart(t_stack **s2, t_stack **b, t_elem **temp, int *arr)//cuando la posicion es 0
{
	pb(*s2, *b);
	if ((*temp)->position > (arr[3] - (arr[2] / 3)) && (*temp)->position <= (arr[3] - (arr[2] / 3 / 2)))
		rb(*b);//en caso de que temp position este abajo hay que moverlo a arriba para hacer pb y por lo tanto que se vayan colocando en Stack B
	return (arr[1] + 1);
}

int	six_to_hundred_3rdpart(t_stack **s2, t_elem **temp, int *arr)//para mover ra rra
{
	if (arr[0] <= (*s2)->size / 2)
		ra(*s2);//en caso de que pos no sea 0, que queremos qe sea 0 para hacer pb, haz ra para que ses pos 0
	else
		rra(*s2);// si lo primero no es pues rra porque estra abajo del todo
	(*temp) = (*s2)->first;
	return (0);
}

void	six_to_hundred(t_stack **s2, t_stack **b)
{
	int		arr[4];
	t_elem	*temp;//variable temporal primer elemento de s2(A)

	arr[0] = 0;	// (pos) posicion real de los numeros que se va recorriendo
	arr[1] = 0; // (count) numero de numeros pasados con pb
	arr[2] = (*s2)->size; // (size) size fijo de la stack
	arr[3] = ((*s2)->size / 3); // (group) valor para comparar la position, cantidad de numeos en la qu se divide un grupo
	temp = (*s2)->first;
	while((*s2)->size != 0)//mientras el tamano de size no sea zero
	{
		if (temp->position <= arr[3])// posicion de temp es mas pequena o igual que grup,es que esta dentro de lo que queremos coger
		{	
			if (arr[0] == 0)
				arr[1] = six_to_hundred_2ndpart(s2, b, &temp, arr);
			arr[0] = six_to_hundred_3rdpart(s2, &temp, arr);
		} 
		else //todo esto para que cuando ya ha acabado la movida pasar a la siguiente posicion y seguir
		{
			temp = temp->next;
			arr[0]++;
		}
		if (arr[1] == arr[3])
			arr[3] = arr[3] + (arr[2] / 3);
	}
	push_back_to_A(s2, b);
}
