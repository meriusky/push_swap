/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:15:51 by mehernan          #+#    #+#             */
/*   Updated: 2023/01/10 15:24:17 by mehernan         ###   ########.fr       */
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

//When you execute a C program, command line arguments are made available to the function main in two parameters, an argument count, conventionally called argc, and an argument vector, conventionally called argv. (Every C program is required to have an entry point named main.) argc is the number of arguments with which the program was invoked. argv is an array of pointers to character strings that contain the arguments, one per string. Since the command name itself is considered to be the first argument, or argv[0], the count is always at least one. Here is the declaration for main:

int main(int argc, char *argv[]) //falata chequear si los argumentos son números y si no lo son mostrar error
{
	t_stack *s2 = init_stack();

	if(argc < 3) //esto era argc = 1 pero hubo problema linux 
		return(0);
	check_num(argv);
//	(void)argv;
	
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
	rrb(s3);
//	printf("S2\n");
//	print_stack(s2);
	printf("S3\n"); 
	print_stack(s3);
	printf("\n");
//	printf("%d\n", get_top(s2));
//	rra(s2);
	rrb(s3);
//	printf("S2\n");
//	print_stack(s2);
//	printf("\n");
//	printf("%d\n", get_top(s2));

	printf("TEST ROTATE\n");
	printf("BEFORE ROTATE\n");
	printf("S3\n");
	print_stack(s3);
	rb(s3);
	printf("\n");
	print_stack(s3);

	printf("TEST SWAP A y B at the same time\n");
	printf("BEFORE\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	ss(s2, s3);
	printf("\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);

	printf("TEST ROTATE A y B at the same time\n");
	printf("BEFORE\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	rr(s2, s3);
	printf("\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);

	printf("TEST REVERSE ROTATE A y B at the same time\n");
	printf("BEFORE\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);
	rrr(s2, s3);
	printf("\n");
	printf("S2\n");
	print_stack(s2);
	printf("\n");
	printf("S3\n");
	print_stack(s3);

	printf("TEST PUSH A :first element of B at the top of A\n");
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

	printf("TEST PUSH B :first element of A at the top of B\n");
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
