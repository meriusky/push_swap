/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:32:30 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/12 17:09:31 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"

//Buscar el numero mas pequeno y darle 1 de posicion
//seguir asi adelante
void	push_back_to_A_2ndpart(t_stack **s2, t_stack **b, t_elem **tempb, int *count)
{
	if(*count == 1)//es decir esta en la primera posicion, ya que no necesitamos recorrer nada ya que el num que queremos esta al inicio
	{
		pa(*s2, *b);
		*tempb = (*b)->first;
	}
	else// con esto lo que hacemos es ir meneanddo el numero que queremos para que llege a ser el primero y pushearlo
	{
		if(*count <= (((*b)->size) / 2))// dividido para saer si hacer rr o solo r segun lo arriba que este
			rb(*b);
		else
			rrb(*b);
		*tempb = (*b)->first;
		*count = 1;
	}
}
void	push_back_to_A_3rdpart(t_stack **s2, t_stack **b, t_elem **tempb, int *arr)
{
	if(arr[1] == 1)
	{
		pa(*s2, *b);
		sa(*s2);
		*tempb = (*b)->first;
		arr[0] = 0;
	}
	else
	{
		if(arr[1] <= (((*b)->size) / 2))
			rb(*b);
		else
			rrb(*b);
		*tempb = (*b)->first;
		arr[1] = 1;
	}
}
void	push_back_to_A_4thpart(t_elem **tempb, int *count)
{
	*tempb = (*tempb)->next;
	*count = *count + 1;
}

void	push_back_to_A(t_stack **s2, t_stack **b)
{
	t_elem	*tempb; //variable temporal sobre el primer elemento de B
//	int		flag; //indicador de si hemos pasado un numero a A que debera ser movido en A por el siguiente + grande
//	int		count;//contador para recorrer la stack b
	int		arr[2];

	tempb = (*b)->first;
	arr[0] = 0;//flag, el indicador de si hemos pasado un numero a A que debera ser movido en A por el siguiente + grande
	arr[1] = 1;//count, contador para recorrer la stack b, es uno, ya que en un futuro lo usaremoos para saber si un num sta a la mitad y al dividir, 0 n se cuenta como num
	while ((*b)->size)//mientras haya algo dentro de b  el tamano no ses 0, seguimos recorriendo la stack
	{//hay casos en los que querremos pasar ds numeros y luego moverlos en la stack A, por eso existe el primer if. En caso que el de abajo sea el numero que estemos buscado pasamos el primero y luego el segundo. Es algo para asi hacer menos movimientos.
		if((*b)->first->position == ((*b)->size - 1) && arr[0] == 0)//si la posicion es igual al size - 1 significa que es un num inferior al que estamos buscando y lo podemos pushear para moverlos en el otro stack
		{
			pa(*s2, *b);
			arr[0] = 1;//es uno ya que ya hemos movido un numero anterior a la stack A
			tempb = (*b)->first;// hacemos que el puntero senale otra vez al inicio porque sino senalaria  la otra stack
		}
		else
		{
			if(tempb->position == (*b)->size && arr[0] == 0)
					push_back_to_A_2ndpart(s2, b, &tempb, &arr[1]);
			else if (tempb->position == ((*b)->size + 1) && arr[0] == 1)//size + 1 ya que hemos pasado ya un numerito asi que no va a ser ==
					push_back_to_A_3rdpart(s2, b, &tempb, arr);
			else
					push_back_to_A_4thpart(&tempb, &arr[1]);
		}
	}
}

