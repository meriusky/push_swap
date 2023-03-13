/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:26:25 by mehernan          #+#    #+#             */
/*   Updated: 2023/03/13 20:00:25 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"

// This file contains the algoridm that orders the quantity greater that five numbers.
// Dividir la stack A en 3 grupos de mas pequenos a mas grandes
// Llevar cada grupo a la stack b
// Llevar de vuelta todos los numeros a la stack uno por uno de mayor a menor
/*
int	six_to_hundred(t_stack *s2, t_stack *b)//quizas es **X pero no lo se seguro, quizas no es int y es t_stack
{

}
*/

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
			if (temp->value > count->value && count->position == 0)//si temp es mayor al valor del que se compara i la posicion de este es 0, es decir que no se ha guardado aun, que se guarde ya que eso quiere decir que el ultimo de la estac es mas pequeno que el actual temp asi que le damos una posicion a count
				count->position = position;
			else//si lo anterior no sucede pues hacemos lo mismo solo que guardando el teo en vez de el count
				temp->position = position;
			position = position + 1;// que sea +1 hace que cada posicion que se adjunta sea superior a la anterioir
			temp = (*s2)->first;
			count = temp->next;
			continue ;//para que vuelva a empezar en while desde el principio
		}
		if (count->position != 0)// si se da el caso que count ya ha sido guardado no debemos comparar temp con ese asi que avanzamos el count al siguiente
			count = count->next;
		else
		{
			temp = count;//si no entra, el valor de count es menor, asi que temp sea count mejor que dar vueltas xd
			count = temp->next;
		}
	}
}
