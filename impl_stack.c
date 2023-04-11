/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:44:55 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/11 12:38:46 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdlib.h>

t_stack	*init_stack(void)
{
	t_stack	*save;

	save = malloc(sizeof(t_stack));
	if (!save)
		return (NULL);
	save->size = 0;
	save->first = NULL;
	return (save);
}
//Todas las funciones son void, pero puede que lo dejen de ser

void	push(t_stack *s, int value) //añade un elemento a la stack//es necesario que sea al reves
{
	t_elem	*newelem;
	t_elem	*count;

	newelem = malloc(sizeof(t_elem));
	//if(!newelem)         //NO QUITAR, comentado porque la funcion es VOID cuando no lo sea servira
	//	return(NULL);
	newelem->next = NULL;// para  que next no tenga un valor erroneo, y vaya a algo de memoria que no debes usar
	newelem->value = value;
	newelem->position = 0;
	if (s->first == NULL)
		s->first = newelem;
	else
	{
		count = s->first;
		while (count->next != NULL)
		{
			count = count->next;
		}
		count->next = newelem;
	}
	s->size++;
/*	newelem->value = value; //value esta dentro de newelem
	newelem->next = s->first; //el siguente elemento al que apunta newelem es el que era el primero en la stack
	s->first = newelem; //el first elemnto de s(que es la stack, porque la hemos declarado como t_stack) es newelem
	s->size++; //s suma size cada vez que haya un newelem evidentemente*/
}
void	pop(t_stack *s)
{
	t_elem	*first; // si,una estructura puede ser puntero

	first = s->first; //first es igual al primer elemento de la stack, chica lo guardas porque esto no es una statica 
	s->first = first->next; //el first elemento de s es igual al siguiente elemento despues de first
	free(first); //hacemos free porque como ahora el first es el antiguo segundo elemento el primero primero está ahí en ningún sitio. (recuerda que las flechas no son =)
	s->size--; // menos menos porque acabas de hacer pop y quitando uno
}
/*
int	get_top(t_stack *s)// funcion que hice para comprovar que el value se ponia en la primera posicion pero ya no uso, quizas la borre
{
	return(s->first->value);
}
*/
