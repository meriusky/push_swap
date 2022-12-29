/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:44:55 by mehernan          #+#    #+#             */
/*   Updated: 2022/12/29 23:02:41 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_elem
{
	int		value;
	struct s_elem	*next;
}t_elem;

typedef struct stack
{
	struct s_elem	*first;
	int	size;
}t_stack;

int	*init_stack()
{
	t_stack	*save;

	save = malloc(sizeof(stack));
	if(!save)
		return(NULL);
	t_stack->size=0;
	return(save);
}

void push(stack *s, int value) //añade un elemento a la stack
{
	s_elem *elem;
	
	elem = malloc(sizeof(s_elem));
	if(!elem)
		return(NULL);
	elem->value = value;
	elem->next = s->first;
	s->first = elem:
	stack->size++;
}

void pop(stack *s)
{
	s_elem* first = s.first;
	s->first = first->next;
	free(first);
	s->size--;
}
