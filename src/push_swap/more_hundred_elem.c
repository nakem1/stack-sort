/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_hundred_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:20:19 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/09 19:00:46 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		work_with_zeroindex(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*min;

	min = *stack_a;
	tmp = (*stack_a)->next;
	while (tmp)
	{
		if (*(int *)min->content > *(int *)tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	min->flag = 1;
	min->index = 0;
}

void		set_index(t_list **stack_a, int size_stack)
{
	int		i;
	t_list	*tmp;
	t_list	*min;

	i = 1;
	work_with_zeroindex(stack_a);
	while (i < size_stack)
	{
		tmp = *stack_a;
		while (tmp && tmp->flag == 1)
			tmp = tmp->next;
		min = tmp;
		tmp = tmp->next;
		while (tmp)
		{
			if (*(int *)min->content > *(int *)tmp->content && tmp->flag == 0)
				min = tmp;
			tmp = tmp->next;
		}
		min->flag = 1;
		min->index = i;
		i++;
	}
}

int			*get_heaps(int size_stack)
{
	int		*heaps;
	int		size_one_heap;

	heaps = (int *)malloc(sizeof(int) * 6);
	size_one_heap = size_stack / 5;
	heaps[0] = 0;
	heaps[1] = size_one_heap;
	heaps[2] = size_one_heap * 2;
	heaps[3] = size_one_heap * 3;
	heaps[4] = size_one_heap * 4;
	heaps[5] = size_stack;
	return (heaps);
}

void		more_hundred_elem(t_list **stack_a, t_list **stack_b,
		int size_stack)
{
	int		*heaps;

	set_index(stack_a, size_stack);
	heaps = get_heaps(size_stack);
	while (size_stack != 0)
	{
		reset_flag(stack_a);
		find_optimal(heaps, stack_a);
		stack_reduction(stack_a, stack_b, &size_stack, "pb\n");
	}
	size_stack = ft_list_size(*stack_b);
	while (size_stack != 0)
	{
		reset_flag(stack_b);
		find_minmax(stack_b, MAX);
		stack_reduction(stack_b, stack_a, &size_stack, "pa\n");
	}
}
