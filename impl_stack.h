/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:24:34 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/09 19:27:45 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_elem
{
        int             value;
        struct s_elem   *next;
		int				position;
}t_elem;

typedef struct s_stack
{
        struct s_elem   *first;
        int     size;
}t_stack;

t_stack *init_stack();
void	print_stack(t_stack *s);
void	push(t_stack *s, int value);
void	pop(t_stack *s);
int		get_top(t_stack *s);
void	sa(t_stack *s1);
void	sb(t_stack *s2);
void	ss(t_stack *s1, t_stack *s2);
void	pa(t_stack *s1, t_stack *s2);
void	pb(t_stack *s1, t_stack *s2);
t_elem	*get_penultimate_elem(t_stack *s);
void	ra(t_stack *s1);
void	rb(t_stack *s2);
void	rr(t_stack *s1, t_stack *s2);
void	rra(t_stack *s1);
void	rrb(t_stack *s2);
void	rrr(t_stack *s1, t_stack *s2);
int		check_num(char *c[]);
int		check_int(char *c[]);
int		ft_strlen(char *s);
int		converter(char str[]);
int		check_dplnum(char *c[]);
int		ft_atoi(const char *str);
int		sorted_check(int argc, t_stack **s2, t_stack **b);
void	sorting(int argc, t_stack **s2, t_stack **b);
t_stack	*two_num(t_stack *s2);
t_stack	*three_num(t_stack *s2);
t_stack	*three_num_2ndpart(t_stack *s2, t_elem *p1, t_elem *p2, t_elem *p3);
t_stack	*four_num(t_stack *s2, t_stack *b);
t_stack	*four_num_2ndpart(t_stack *s2, t_stack *b);
t_stack	*five_num(t_stack *s2, t_stack *b);
t_stack	*five_num_2ndpart(t_stack *s2, t_stack *b);
t_stack	*five_num_3rdpart(t_stack *s2, t_stack *b);
void	six_to_hundred(t_stack **s2, t_stack **b);
void	give_position(t_stack **s2);
void	give_position_2nd(t_stack **s2, t_elem **count, t_elem **temp, int *pos);
void	give_position_3rd(t_elem **count, t_elem **temp);
void	push_back_to_A(t_stack **s2, t_stack **b);
void	more_than_hundred(t_stack **s2, t_stack **b);
