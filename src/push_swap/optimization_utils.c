/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 06:12:44 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 22:18:59 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		topmove_stack_b(t_list **stack_b, int position, int steps,
		int direction)
{
	int i;

	i = 0;
	if (direction == TOP)
	{
		while (i++ < position)
		{
			if (steps-- > 0)
			{
				rotate(stack_b, "rr\n");
				rotate(g_norm_a, NULL);
			}
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

void		botmove_stack_b(t_list **stack_b, int position, int steps,
		int direction)
{
	int i;
	int size_stack;

	i = position;
	size_stack = ft_list_size(*stack_b);
	if (direction == BOTTOM)
	{
		while (i++ < size_stack)
		{
			if (steps-- > 0)
			{
				reverse_rotate(stack_b, "rrr\n");
				reverse_rotate(g_norm_a, NULL);
			}
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
