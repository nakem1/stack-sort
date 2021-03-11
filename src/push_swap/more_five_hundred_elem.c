/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_five_hundred_elem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:45:08 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/11 06:18:21 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
