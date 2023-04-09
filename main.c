/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:15:51 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/09 19:54:31 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "impl_stack.h"

void	print_stack(t_stack *s)// esta funcion acabara desapareciendo, ya que hay que printear movimientos
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
		printf("Elem: %d\tPos: %d\n", elem->value, elem->position);
		elem = elem->next;
	}
	printf("\n");
}
int main(int argc, char *argv[])
{
	if(argc < 3) //esto era argc = 1 pero hubo problema linux 
		return(0);
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
 	t_stack *b = init_stack();// debo iniciar una stack b para usarla en el four_num, ya veremos cmo

//PORQUE HACEMOS ESTO? si la stack esta ordenada tenemos que ostrarla sin ningun cambio. Ahora mismo, la stack esta vacia, asi que haremos push con los argv. 
	int i;

	i = 1;
	while (argv[i] != NULL)//Hacemos while para poder passar un * en vez de doble**, para que lo pase a int
	{
		push(s2, converter(argv[i]));
		i++;
	}
//	printf("A\n");
//	print_stack(s2);
//	printf("B\n");
//	print_stack(b);
//	printf("\n");
//	printf("TEST PUSH/POP\n");
	if (!sorted_check(argc, &s2, &b))
	{
//		printf("ya estaban ordenados\n");
//		print_stack(s2);
		return (0);
	}
//	printf("A\n");
//	print_stack(s2);
//	printf("B\n");
//	print_stack(b);
//	printf("\n");
//FIN DE LA PRIMERA PARTE
//	print_stack(s2);
//	printf("%d\n", get_top(s2));
//	pop(s2);
//	printf("%d\n", get_top(s2));
//	pop(s2);
//	printf("%d\n", get_top(s2));
/*	printf("\n");
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
	print_stack(s3);*/
}
