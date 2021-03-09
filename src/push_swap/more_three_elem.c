/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:34:35 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/09 02:43:10 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		reset_flag(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->flag = 0;
		tmp = tmp->next;
	}
}

void		astack_recovery(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b != NULL)
	{
		push(stack_b, stack_a, "pa\n");
		print_list(*stack_a, *stack_b);
		if ((*(int *)((*stack_a)->content)) >
				(*(int *)((*stack_a)->next->next->next->content)))
		{
			rotate(stack_a, "ra\n");
			print_list(*stack_a, *stack_b);
		}
	}
}

void		find_minmax(t_list **stack, int minmax)
{
	t_list		*max;
	t_list		*min;
	t_list		*tmp;

	max = *stack;
	min = *stack;
	tmp = (*stack)->next;
	while (tmp)
	{
		if (minmax == MAX)
			max = *(int *)max->content < *(int *)tmp->content ? tmp : max;
		else
			min = *(int *)min->content > *(int *)tmp->content ? tmp : min;
		tmp = tmp->next;
	}
	if (minmax == MAX)
		max->flag = 1;
	else
		min->flag = 1;
}

void		more_three_elem(t_list **stack_a, t_list **stack_b, int size_stack)
{
	while (size_stack != 3)
	{
		reset_flag(stack_a);
		find_minmax(stack_a, MIN);
		find_minmax(stack_a, MAX);
		stack_reduction(stack_a, stack_b, &size_stack, "pb\n");
	}
	handle_three_elem(stack_a);
	astack_recovery(stack_a, stack_b);
}
