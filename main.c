/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:15:51 by mehernan          #+#    #+#             */
/*   Updated: 2023/01/08 20:24:23 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "impl_stack.h"
#include <stdio.h>

void	print_stack(t_stack *s)
{
	t_elem	*elem;

	if (s->first == NULL)
	{
		printf("Empty\n");
		return ;
	}
	elem = s->first;
	while (elem != NULL)
	{
		printf("Elem: %d\n", elem->value);
		elem = elem->next;
	}
}

int main(int argc, char *argv[])
{
	t_stack *s2 = init_stack();

	if(argc == 1) //esto era argc = 1 pero hubo problema linux
		return(0);
	(void)argv;
	
	printf("TEST PUSH/POP\n");

	push(s2, 23);
	printf("%d\n", get_top(s2));
	pop(s2);
	push(s2, 1);
	printf("%d\n", get_top(s2));
	push(s2, 2);
	printf("%d\n", get_top(s2));
	push(s2, 3);
	printf("%d\n", get_top(s2));
//	pop(s2);
//	printf("%d\n", get_top(s2));
	
	printf("TEST SWAP\n");
	t_stack *s3 = init_stack();
	push(s3, 4);
	push(s3, 5);
	push(s3, 6);
	push(s3, 7);
	printf("BEFORE SWAP\n");
//	print_stack(s2);
	sa(s3);
	printf("S2\n");
	print_stack(s2);
	printf("S3\n");
	print_stack(s3);
	printf("\n");
//	printf("%d\n", get_top(s2));
//	printf("%d\n", get_top(s3));
	printf("TEST REVERSE ROTATE\n");
	printf("BEFORE REVERSE ROTATE\n");
//	rra(s2);
	print_stack(s3);
	rra(s3);
//	printf("S2\n");
//	print_stack(s2);
	printf("S3\n");
	print_stack(s3);
	printf("\n");
//	printf("%d\n", get_top(s2));
//	rra(s2);
	rra(s3);
//	printf("S2\n");
//	print_stack(s2);
//	printf("\n");
//	printf("%d\n", get_top(s2));
	printf("TEST ROTATE\n");
	printf("BEFORE ROTATE\n");
	printf("S3\n");
	print_stack(s3);
	ra(s3);
	printf("\n");
	print_stack(s3);
	

}
