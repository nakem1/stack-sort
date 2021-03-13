/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:04:43 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/13 07:06:34 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void		sort_b(int *heaps, int size_heaps, t_list **stack_a,
// 		t_list **stack_b)
// {
// 	t_list	*tmp;
// 	int		i;
// 	int		size_stack;

// 	size_stack = ft_list_size(*stack_a);
// 	tmp = *stack_a;
// 	(*stack_a)->flag = 2;
// 	i = 0;
// 	find_optimal(heaps, size_heaps, stack_a);
// 	find_min_dist(stack_a, size_stack);
// 	while (tmp)
// 	{
// 		if (tmp->flag == 1)
// 		{
// 			if (i < (size_stack / 2))
// 		}
// 		i++;
// 	}
// }

void		staging_stack_b(t_list **stack_b, int position, int steps,
		int direction)
{
	int		i;
	int		size_stack;

	size_stack = ft_list_size(*stack_b);
	i = 0;
	if (size_stack > 1)
	{
		if (position < (size_stack / 2))
		{
			if (direction == TOP)
			{
				while (i++ < position)
				{
					if (steps-- > 0)
						rotate(stack_b, "rr\n");
					else
						rotate(stack_b, "rb\n");
				}
			}
			else
			{
				while (i++ < position)
					rotate(stack_b, "rb\n");
			}
		}
		else
		{
			i = position;
			if (direction == BOTTOM)
			{
				while (i++ < size_stack)
				{
					if (steps-- > 0)
						reverse_rotate(stack_b, "rrr\n");
					else
						reverse_rotate(stack_b, "rrb\n");
				}
			}
			else
			{
				while (i++ < size_stack)
					reverse_rotate(stack_b, "rrb\n");
			}
		}
	}
}

void		insert_min(t_list **stack_b, int steps, int direction)
{
	t_list	*min;
	t_list	*tmp;
	int		i;

	i = 0;
	if (*stack_b)
	{
		min = *stack_b;
		tmp = (*stack_b)->next;
		while (tmp)
		{
			if (*(int *)min->content > *(int *)tmp->content)
			{
				min = tmp;
				i++;
			}
			tmp = tmp->next;
		}
	}
	staging_stack_b(stack_b, i, steps, direction);
}

void		insert_max(t_list *target, t_list **stack_b, int steps,
		int direction)
{
	t_list	*max;
	t_list	*tmp;
	int		i;

	i = 0;
	max = NULL;
	tmp = *stack_b;
	while (tmp)
	{
		if (max == NULL)
		{
			if (*(int *)target->content < *(int *)tmp->content)
			{
				max = tmp;
				i++;
			}
		}
		else
		{
			if (*(int *)target->content < *(int *)tmp->content &&
					*(int *)max->content > *(int *)tmp->content)
			{
				max = tmp;
				i++;
			}
		}
		tmp = tmp->next;
	}
	staging_stack_b(stack_b, i, steps, direction);
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
