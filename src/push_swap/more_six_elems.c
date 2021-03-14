/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_six_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:34:35 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 04:25:09 by lmurray          ###   ########.fr       */
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

void		more_six_elems(t_list **stack_a, t_list **stack_b, int size_stack)
{
	while (size_stack != 0)
	{
		reset_flag(stack_a);
		find_minmax(stack_a, MIN);
		find_minmax(stack_a, MAX);
		stack_reduction(stack_a, stack_b, &size_stack, A_STACK);
	}
	size_stack = ft_list_size(*stack_b);
	while (*stack_b != NULL)
	{
		reset_flag(stack_b);
		find_minmax(stack_b, MAX);
		stack_reduction(stack_b, stack_a, &size_stack, B_STACK);
	}
}
