/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:34:41 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/15 16:38:17 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **s)
{
	t_elem	*temp;
	t_elem	*save;

	temp = (*s)->first;
	while (temp != NULL)
	{
		save = temp;
		temp = temp->next;
		free(save);
	}
	free(*s);
}
