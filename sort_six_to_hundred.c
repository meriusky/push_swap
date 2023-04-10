/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_to_hudred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:26:25 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/10 19:50:37 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"

// This file contains the algoridm that orders the quantity greater that five numbers.
// Dividir la stack A en 3 grupos de mas pequenos a mas grandes
// Llevar cada grupo a la stack b
// Llevar de vuelta todos los numeros a la stack uno por uno de mayor a menor

// void	push_numbers_to_B(t_stack **s2, t_stack **b, t_elem *temp, int *arr);

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
				arr[1] = first_pos(s2, b, &temp, arr);
			arr[0] = make_move(s2, &temp, arr);
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

int	first_pos(t_stack **s2, t_stack **b, t_elem **temp, int *arr)//cuando la posicion es 0
{
	pb(*s2, *b);
	if ((*temp)->position > (arr[3] - (arr[2] / 3)) && (*temp)->position <= (arr[3] - (arr[2] / 3 / 2)))
		rb(*b);//en caso de que temp position este abajo hay que moverlo a arriba para hacer pb y por lo tanto que se vayan colocando en Stack B
	return (arr[1] + 1);
}

int	make_move(t_stack **s2, t_elem **temp, int *arr)//para mover ra rra
{
	if (arr[0] <= (*s2)->size / 2)
		ra(*s2);//en caso de que pos no sea 0, que queremos qe sea 0 para hacer pb, haz ra para que ses pos 0
	else
		rra(*s2);// si lo primero no es pues rra porque estra abajo del todo
	(*temp) = (*s2)->first;
	return (0);
}

void	push_back_to_A(t_stack **s2, t_stack **b)
{
	t_elem	*tempb; //variable temporal sobre el primer elemento de B
	int		flag; //indicador de si hemos pasado un numero a A que debera ser movido en A por el siguiente + grande
	int		count;//contador para recorrer la stack b

	tempb = (*b)->first;
	flag = 0;
	count = 1;// es uno, ya que en un futuro lo usaremoos para saber si un num sta a la mitad y al dividir, 0 n se cuenta como num
	while ((*b)->size)//mientras haya algo dentro de b  el tamano no ses 0, seguimos recorriendo la stack
	{//hay casos en los que querremos pasar ds numeros y luego moverlos en la stack A, por eso existe el primer if. En caso que el de abajo sea el numero que estemos buscado pasamos el primero y luego el segundo. Es algo para asi hacer menos movimientos.
		if((*b)->first->position == ((*b)->size - 1) && flag == 0)//si la posicion es igual al size -1 significa que es un num inferior al que estamos buscando y lo podemos pushear para moverlos en el otro stack
		{
			pa(*s2, *b);
			flag = 1;//es uno ya que ya hemos movido un numero anterior a la stack A
			tempb = (*b)->first;// hacemos que el puntero senale otra vez al inicio porque sino senalaria  la otra stack
		}
		else
		{
		if(tempb->position == (*b)->size && flag == 0)
				push_back_to_A_2ndpart(s2, b, &tempb, &count);
		else if (tempb->position == ((*b)->size + 1) && flag == 1)//size +1 ya que hemos pasado ya un numerito asi que no va a ser ==
				push_back_to_A_3rdpart(s2, b, &tempb, &flag, &count);
		else
				push_back_to_A_4thpart(&tempb, &count);
		}
	}
}

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
void	push_back_to_A_3rdpart(t_stack **s2, t_stack **b, t_elem **tempb, int *flag, int *count)
{
	if(*count == 1)
	{
		pa(*s2, *b);
		sa(*s2);
		*tempb = (*b)->first;
		*flag = 0;
	}
	else
	{
		if(*count <= (((*b)->size) / 2))
			rb(*b);
		else
			rrb(*b);
		*tempb = (*b)->first;
		*count = 1;
	}
}
void	push_back_to_A_4thpart(t_elem **tempb, int *count)
{
	*tempb = (*tempb)->next;
	*count = *count + 1;
}

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
