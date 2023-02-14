/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:15:51 by mehernan          #+#    #+#             */
/*   Updated: 2023/02/14 19:26:37 by mehernan         ###   ########.fr       */
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
int main(int argc, char *argv[]) //puede que la primera parte de esta funcio vaya a impl_stack.c
{
	if(argc < 2) //esto era argc = 1 pero hubo problema linux 
	{
		printf("ERROR\n");
		printf("less that to numbers\n");
		return(0);
	}
	if(check_num(argv) == 0)
	{
		printf("Only numbers are allowed\n");
		printf("ERROR\n");
		return (0);
	}
	if(check_int(argv) == 0)
	{
		printf("Just int size allowed\n");
		printf("ERROR\n");
		return (0);
	}
	if(check_dplnum(argv) == 0)
	{
		printf("Duplicate numbers not allowed\n");
		printf("ERROR\n");
		return (0);
	}
	t_stack *s2 = init_stack();//antes estaba al prinipio, pero para ahorrar memoria es mejor comprobar todo y luego iniciar la stack
//FIN PRIMERA PARTE
//	(void)argv;
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		push(s2, converter(argv[i]));
		i++;
	}
	printf("TEST PUSH/POP\n");
	int	res;
	res = sorted_check(argc, &s2);
	if (!res)
	{
		print_stack(s2);
		return (0);
	}
/*
	s2 = sorted_check(argc, s2);
	if(s2 != NULL)
		print_stack(s2);
*/
//	print_stack(s2);
//	printf("%d\n", get_top(s2));
//	pop(s2);
//	printf("%d\n", get_top(s2));
//	pop(s2);
//	printf("%d\n", get_top(s2));
	printf("\n");
	printf("TEST SWAP\n");
	t_stack *s3 = init_stack();
	push(s3, 4);
//	push(s3, 5);
//	push(s3, 6);
//	push(s3, 7);
	printf("BEFORE SWAP above AFTER SWAP below--------\n");
	print_stack(s2);
	sa(s2);
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	printf("\n");
//	printf("%d\n", get_top(s2));
//	printf("%d\n", get_top(s3));
	printf("TEST REVERSE ROTATE--------\n");
	printf("BEFORE REVERSE ROTATE\n");
//	rra(s2);
	print_stack(s2);
	printf("AFTER REVERSE ROTATE\n");
	rra(s2);
	printf("S2\n");
	print_stack(s2);
	printf("S3\n"); 
	print_stack(s3);
	printf("\n");
//	printf("%d\n", get_top(s2));
//	rrb(s3);
//	printf("S2\n");
//	print_stack(s2);
//	printf("\n");
//	printf("%d\n", get_top(s2));
	printf("\n");

	printf("TEST ROTATE--------\n");
	printf("BEFORE ROTATE\n");
	printf("S2\n");
	print_stack(s2);
//	print_stack(s3);
	printf("AFTER ROTATE\n");
	printf("S2\n");
	ra(s2);
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	printf("\n");

	printf("TEST SWAP A y B-------- at the same time\n");
	printf("BEFORE\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	ss(s2, s3);
	printf("\n");
	printf("AFTER\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	printf("\n");

	printf("TEST ROTATE A y B-------- at the same time\n");
	printf("BEFORE\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	printf("AFTER\n");
	rr(s2, s3);
	printf("\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	printf("\n");

	printf("TEST REVERSE ROTATE A y B-------- at the same time\n");
	printf("BEFORE\n");
	printf("\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	printf("\n");
	printf("AFTER\n");
	rrr(s2, s3);
	printf("\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	printf("\n");

	printf("TEST PUSH A--------first element of B at the top of A\n");
	printf("BEFORE\n");
	printf("STACK A\n");
	print_stack(s2);
	printf("\n");
	printf("STACK B\n");
	print_stack(s3);
	pa(s2, s3);
	printf("\n");
	printf("AFTER\n");
	printf("STACK A\n");
	print_stack(s2);
	printf("\n");
	printf("STACK B\n");
	print_stack(s3);
	printf("\n");

	printf("TEST PUSH B--------first element of A at the top of B\n");
	printf("BEFORE\n");
	printf("STACK A\n");
	print_stack(s2);
	printf("\n");
	printf("STACK B\n");
	print_stack(s3);
	pb(s2, s3);
	printf("\n");
	printf("AFTER\n");
	printf("STACK A\n");
	print_stack(s2);
	printf("\n");
	printf("STACK B\n");
	print_stack(s3);
}
