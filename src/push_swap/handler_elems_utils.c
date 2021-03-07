/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_elems_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:40:07 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/07 03:11:24 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		select_how_gotop(t_list **stack, int size_stack, int position)
{
	int i;

	i = 0;
	if (i < (size_stack / 2))
	{
		while (i < position)
		{
			rotate(stack, "ra\n");
			print_list(*stack, NULL);
			i++;
		}
	}
	else
	{
		i = position;
		while (i < size_stack)
		{
			reverse_rotate(stack, "rra\n");
			print_list(*stack, NULL);
			i++;
		}
	}
}

void		stack_reduction(t_list **stack_a, t_list **stack_b, int *size_stack)
{
	int		i;
	int		flag_find;
	t_list	*tmp;

	i = 0;
	flag_find = 0;
	tmp = *stack_a;
	while (flag_find != 1)
	{
		if (tmp->flag == 1)
		{
			select_how_gotop(stack_a, *size_stack, i);
			flag_find = 1;
		}
		i++;
		tmp = tmp->next;
	}
	push(stack_a, stack_b, "pb\n");
	print_list(*stack_a, *stack_b);
	*size_stack -= 1;
}
