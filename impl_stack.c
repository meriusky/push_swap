/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:44:55 by mehernan          #+#    #+#             */
/*   Updated: 2023/01/09 20:08:24 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"
#include <stdlib.h>

t_stack	*init_stack()
{
	t_stack	*save;

	save = malloc(sizeof(t_stack));
	if(!save)
		return(NULL);
	save->size = 0;
	save->first = NULL;
	return(save);
}
void	push(t_stack *s, int value) //añade un elemento a la stack
{
	t_elem	*newelem;
	
	newelem = malloc(sizeof(t_elem));
	//if(!newelem)         //NO QUITAR, comentado porque la funcion es VOID cuando no lo sea servira
	//	return(NULL);
	newelem->value = value; //value esta dentro de newelem
	newelem->next = s->first; //el siguente elemento al que apunta newelem es el que era el primero en la stack
	s->first = newelem; //el first elemnto de s(que es la stack, porque la hemos declarado como t_stack) es newelem
	s->size++; //s suma size cada vez que haya un newelem evidentemente
}
void	pop(t_stack *s)
{
	t_elem	*first; // si,una estructura puede ser puntero

	first = s->first; //first es igual al primer elemento de la stack, chica lo guardas porque esto no es una statica 
	s->first = first->next; //el first elemento de s es igual al siguiente elemento despues de first
	free(first); //hacemos free porque como ahora el first es el antiguo segundo elemento el primero primero está ahí en ningún sitio. (recuerda que las flechas no son =)
	s->size--; // menos menos porque acabas de hacer pop y quitando uno
}
int	get_top(t_stack *s)// funcion que hice para comprovar que el value se ponia en la primera posicion pero ya no uso, quizas la borre
{
	return(s->first->value);
}
void	sa(t_stack *s1) //swap, intercambia los dos primeros elementos de A
{
	t_elem	*temp;
	t_elem	*third;

	if(s1->size < 2) // no puede ser menor que 2 porque hay 2 elementos en la stack
		return;
	temp = s1->first; //temp ahora senala a first
	third = s1->first->next->next;
	s1->first = s1->first->next; //s1 first y s2 first apuntan al mismo sitio
	s1->first->next = temp; // el segundo elemmento es temp
	s1->first->next->next = third; //el tercer elemento es third (la 3a caja)

	// s1->first = 57
	// s2->first = 46
	// temp = s1->first 
	// temp = 57
	// s1->first = s2->first
	// s1->first = 46
	// s2->first = 46
	// s2->first = temp
	// s2->first = 57
//	temp = s1->first->next;
//	s1->first->next = s2->first->next;
//	s2->first->next = temp;
}
void	sb(t_stack *s2) // lo mismo que sa
{
	t_elem	*temp;
	t_elem	*third;

	if(s2->size < 2)
		return;
	temp = s2->first;
	third = s2->first->next->next;
	s2->first = s2->first->next;
	s2->first->next = temp;
	s2->first->next->next = third;
}
void	ss(t_stack *s1, t_stack *s2) //sa y sb a la vez
{
	sa(s1);
	sb(s2);
}
void	ra(t_stack *s1)
{
	t_elem	*temp; //temp de temporal
	t_elem	*penultimate_elem;

	if(s1->size < 2)
		return;
	temp = s1->first;
	penultimate_elem = get_penultimate_elem(s1);
	s1->first = s1->first->next; //la primera caja ahora apunta a la segunda
	penultimate_elem->next->next = temp; // temp debe ser el ultimo
	penultimate_elem->next->next->next = NULL; // y ahora anadimos al ultimo de todo null
}
void	rb(t_stack *s2)
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if(s2->size < 2)
		return;
	temp = s2->first;
	penultimate_elem = get_penultimate_elem(s2);
	s2->first = s2->first->next;
	penultimate_elem->next->next = temp;
	penultimate_elem->next->next->next = NULL;
}
void rr(t_stack *s1, t_stack *s2)
{
	ra(s1);
	rb(s2);
}
t_elem	*get_penultimate_elem(t_stack *s)
{
	t_elem	*elem;

	if (s->size < 2)
		return (NULL);
	elem = s->first;
	while (elem != NULL)
	{
		if (elem->next->next == NULL)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
void	rra(t_stack *s1) //rota el ultimo y lo pone arriba
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if (s1->size < 2)
		return;
	temp = s1->first;
	penultimate_elem = get_penultimate_elem(s1);
	s1->first = penultimate_elem->next;
	s1->first->next = temp;
	penultimate_elem->next = NULL;
}
void	rrb(t_stack *s2) 
{
	t_elem	*temp;
	t_elem	*penultimate_elem;

	if (s2->size < 2)
		return;
	temp = s2->first;
	penultimate_elem = get_penultimate_elem(s2);
	s2->first = penultimate_elem->next;
	s2->first->next = temp;
	penultimate_elem->next = NULL;
}
void	rrr(t_stack *s1, t_stack *s2)
{
	rra(s1);
	rrb(s2);
}
