/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:04:43 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 06:21:34 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		staging_stack_b(t_list **stack_b, int position, int steps,
		int direction)
{
	int		size_stack;

	size_stack = ft_list_size(*stack_b);
	if (size_stack > 1)
	{
		if (position < (size_stack / 2))
			topmove_stack_b(stack_b, position, steps, direction);
		else
			botmove_stack_b(stack_b, position, steps, direction);
	}
}

void		insert_min(t_list **stack_b, int steps, int direction)
{
	t_list	*min;
	t_list	*tmp;

	if (*stack_b)
	{
		min = *stack_b;
		tmp = (*stack_b)->next;
		while (tmp)
		{
			if (*(int *)min->content > *(int *)tmp->content)
				min = tmp;
			tmp = tmp->next;
		}
		set_position(stack_b);
		staging_stack_b(stack_b, min->position, steps, direction);
	}
}

void		insert_max(t_list *target, t_list **stack_b, int steps,
		int direction)
{
	t_list	*max;
	t_list	*tmp;

	max = NULL;
	tmp = *stack_b;
	while (tmp)
	{
		if (max == NULL)
		{
			if (*(int *)target->content < *(int *)tmp->content)
				max = tmp;
		}
		else
		{
			if (*(int *)target->content < *(int *)tmp->content &&
					*(int *)max->content > *(int *)tmp->content)
				max = tmp;
		}
		tmp = tmp->next;
	}
	set_position(stack_b);
	staging_stack_b(stack_b, max->position, steps, direction);
}

void		sort_b(t_list **stack_a, t_list **stack_b, int steps, int direction)
{
	t_list	*target;
	t_list	*tmp;
	t_list	*maxmin;

	maxmin = NULL;
	tmp = *stack_b;
	if (direction == TOP)
		target = ft_list_at(*stack_a, steps);
	else
		target = ft_list_at(*stack_a, ft_list_size(*stack_a) - steps);
	while (tmp)
	{
		if (*(int *)target->content < *(int *)tmp->content)
			maxmin = tmp;
		tmp = tmp->next;
	}
	if (maxmin == NULL)
		insert_min(stack_b, steps, direction);
	else
		insert_max(target, stack_b, steps, direction);
}

void		select_what_todo(t_list **stack_a, t_list **stack_b,
		int position)
{
	int		size_stack_a;
	int		direction;
	int		steps;

	norm_a = stack_a;
	size_stack_a = ft_list_size(*stack_a);
	//
	if (position < (size_stack_a / 2))
	{
		steps = position;
		direction = TOP;
	}
	else
	{
		steps = size_stack_a - position;
		direction = BOTTOM;
	}
	sort_b(stack_a, stack_b, steps, direction);
}
