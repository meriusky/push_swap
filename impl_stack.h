/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:24:34 by mehernan          #+#    #+#             */
/*   Updated: 2023/01/27 19:20:27 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_elem
{
        int             value;
        struct s_elem   *next;
}t_elem;

typedef struct s_stack
{
        struct s_elem   *first;
        int     size;
}t_stack;

t_stack *init_stack();
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
