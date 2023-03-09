/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:26:25 by mehernan          #+#    #+#             */
/*   Updated: 2023/03/09 17:50:11 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file contains the algoridm that orders the quantity greater that five numbers.
// Dividir la stack A en 3 grupos de mas pequenos a mas grandes
// Llevar cada grupo a la stack b
// Llevar de vuelta todos los numeros a la stack uno por uno de mayor a menor

int	six_to_hundred(t_stack *s2, t_stack *b)//quizas es **X pero no lo se seguro, quizas no es int y es t_stack
{

}
//Buscar el numero mas pequeno y darle 1 de posicion
//seguir asi adelante
// 
t_stack	*give_position(t_stack *s2)//ns si esta bien
{
	int	count;

	count = 0;
	position = 1;
	while(position != NULL)//mientras no se acaba la stack que vaya pasando de posicion
	{
		while(position->value < count->value)//si el valor de la posicion X es mas pequena que count, que siga comparando
			count++;
		position++;//si no entra en el while es porque el valor de la posicion es mas grande por lo tanto no es el mas pequeno asi que pasamos a la siguiente posicion   
	}
//Aqui faltan cosas, esto no fuurula
}

