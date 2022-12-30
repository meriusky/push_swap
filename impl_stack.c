/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:44:55 by mehernan          #+#    #+#             */
/*   Updated: 2022/12/30 23:39:41 by mehernan         ###   ########.fr       */
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
	save->size=0;
	return(save);
}

void push(t_stack *s, int value) //añade un elemento a la stack
{
	t_elem *newelem;
	
	newelem = malloc(sizeof(t_elem));
	//if(!newelem)
	//	return(NULL);
	newelem->value = value; //value esta dentro de newelem
	newelem->next = s->first; //el siguente elemento al que apunta newelem es el que era el primero en la stack
	s->first = newelem; //el first elemnto de s(que es la stack, porque la hemos declarado como t_stack) es newelem
	s->size++; //s suma size cada vez que haya un newelem evidentemente
}

void pop(t_stack *s)
{
	t_elem* first; // si,una estructura puede ser puntero

	first = s->first; //first es igual al primer elemento de la stack, chica lo guardas porque esto no es una statica 
	s->first = first->next; //el first elemento de s es igual al siguiente elemento despues de first
	free(first); //hacemos free porque como ahora el first es el antiguo segundo elemento el primero primero está ahí en ningún sitio. (recuerda que las flechas no son =)
	s->size--; // menos menos porque acabas de hacer pop y quitando uno
}

int get_top(t_stack *s)
{
	return(s->first->value);
}

void swap(t_stack *s1, t_stack *s2)
{
	if(s1->size < 2 || s2->size < 2) return;
	t_elem *temp = s1->first;
	s1->first = s2->first;
	s2->first = temp;
	temp = s1->first->next;
	s1->first->next = s2->first->next;
	s2->first->next = temp;
}

t_elem *get_penultimate_elem(t_stack *s)
{
	if(s->size < 2) return NULL;
	t_elem * elem = s->first;
	while(elem != NULL){
		if(elem->next->next == NULL)return elem;
		elem = elem->next;
	}
	return NULL;
}

void rotate(t_stack *s)
{
	if(s->size < 2) return;
	t_elem *penultimate_elem = get_penultimate_elem(s);
	t_elem *temp = s->first;
	s->first = penultimate_elem->next;
	penultimate_elem->next = temp;
	
	s->first->next = penultimate_elem->next->next;
	penultimate_elem->next->next = NULL;
}
