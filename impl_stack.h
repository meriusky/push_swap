/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:24:34 by mehernan          #+#    #+#             */
/*   Updated: 2023/01/07 14:15:16 by mehernan         ###   ########.fr       */
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
void push(t_stack *s, int value);
void pop(t_stack *s);
int get_top(t_stack *s);
void sa(t_stack *s1);
t_elem *get_penultimate_elem(t_stack *s);
void rra(t_stack *s);

