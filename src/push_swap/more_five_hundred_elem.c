/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_five_hundred_elem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:45:08 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 04:11:48 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		astack_recovery(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b != NULL)
	{
		push(stack_b, stack_a, "pa\n");
		if ((*(int *)((*stack_a)->content)) >
				(*(int *)((*stack_a)->next->next->next->content)))
		{
			rotate(stack_a, "ra\n");
		}
	}
}

void		stack_reduction_simple(t_list **stack_a, t_list **stack_b,
		int *size_stack)
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
			select_how_gotop(stack_a, *size_stack, i, A_STACK);
			flag_find = 1;
		}
		i++;
		tmp = tmp->next;
	}
	push(stack_a, stack_b, "pb\n");
	print_list(*stack_a, *stack_b);
	*size_stack -= 1;
}

void		more_three_elem(t_list **stack_a, t_list **stack_b, int size_stack)
{
	while (size_stack != 3)
	{
		reset_flag(stack_a);
		find_minmax(stack_a, MIN);
		find_minmax(stack_a, MAX);
		print_list(*stack_a, *stack_b);
		stack_reduction_simple(stack_a, stack_b, &size_stack);
	}
	print_list(*stack_a, *stack_b);
	handle_three_elem(stack_a);
	astack_recovery(stack_a, stack_b);
}

void		more_five_hundred_elem(t_list **stack_a, t_list **stack_b,
		int size_stack)
{
	int		*heaps;
	int		size_heaps;

	size_heaps = 11;
	set_index(stack_a, size_stack);
	heaps = get_heaps(size_stack, size_heaps);
	while (size_stack != 0)
	{
		reset_flag(stack_a);
		find_optimal(heaps, size_heaps, stack_a);
		stack_reduction(stack_a, stack_b, &size_stack, A_STACK);
	}
	size_stack = ft_list_size(*stack_b);
	while (size_stack != 0)
	{
		reset_flag(stack_b);
		find_minmax(stack_b, MAX);
		stack_reduction(stack_b, stack_a, &size_stack, B_STACK);
	}
}
