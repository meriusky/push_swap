/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:34:41 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/12 19:18:18 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "impl_stack.h"

void	free(t_stack *s)
{
	t_elem	temp;
	t_elem	save;

	temp = (s2->first);
	while(temp != NULL)
	{
		save = temp;
		free(save);
	}
	temp->next;
}
