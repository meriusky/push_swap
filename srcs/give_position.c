/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:09:40 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/15 16:48:22 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_position_2ndpart(t_stack **s2, t_elem **c, t_elem **temp, int *pos)
{
	if ((*temp)->value > (*c)->value && (*c)->position == 0)
	{
		(*c)->position = *pos;
		*pos = *pos + 1;
	}
	else
	{
		(*temp)->position = *pos;
		*pos = *pos + 1;
		(*temp) = (*s2)->first;
		(*c) = (*temp)->next;
	}
}

void	give_position_3rdpart(t_elem **c, t_elem **temp)
{
	if ((*c)->position != 0)
		(*c) = (*c)->next;
	else
	{
		(*temp) = (*c);
		(*c) = (*temp)->next;
	}
}

void	give_position(t_stack **s2)
{
	int		position;
	t_elem	*temp;
	t_elem	*c;

	temp = (*s2)->first;
	position = 1;
	c = temp->next;
	while (temp != NULL)
	{
		while (temp != NULL && temp->position != 0)
			temp = temp->next;
		if (temp == NULL)
			break ;
		while (temp->value < c->value && c->next != NULL)
			c = c->next;
		if (c->next == NULL)
		{
			give_position_2ndpart(s2, &c, &temp, &position);
			continue ;
		}
		give_position_3rdpart(&c, &temp);
	}
}
