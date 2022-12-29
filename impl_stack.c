/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:44:55 by mehernan          #+#    #+#             */
/*   Updated: 2022/12/29 23:23:28 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_elem
{
	int		value;
	struct s_elem	*next;
}t_elem;

typedef struct s_stack
{
	struct s_elem	*first;
	int	size;
}t_stack;

t_stack	*init_stack()
{
	t_stack	*save;

	save = malloc(sizeof(stack));
	if(!save)
		return(NULL);
	save->size=0;
	return(save);
}

void push(stack *s, int value) //añade un elemento a la stack
{
	t_elem *elem;
	
	elem = malloc(sizeof(s_elem));
	if(!elem)
		return(NULL);
	elem->value = value;
	elem->next = s->first;
	s->first = elem:
	s->size++;
}

void pop(t_stack *s)
{
	s_elem* first // si,una estructura puede ser puntero

	first = s->first;
	s->first = first->next;
	free(first);
	s->size--;
}
