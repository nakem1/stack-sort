/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:55:51 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/24 12:30:54 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;
	int		size_stack;

	stack_b = NULL;
	size_stack = ft_lstsize(*stack_a);
	if (size_stack > 1)
	{
		if (size_stack == 2)
			handle_two_elem(stack_a);
		else if (size_stack == 3)
			handle_three_elem(stack_a);
		else if (size_stack > 3 && size_stack < 7)
			more_three_elem(stack_a, &stack_b, size_stack);
		else if (size_stack >= 7 && size_stack < 90)
			more_six_elems(stack_a, &stack_b, size_stack);
		else if (size_stack >= 100 && size_stack < 500)
			more_hundred_elem(stack_a, &stack_b, size_stack);
		else if (size_stack >= 500)
			more_five_hundred_elem(stack_a, &stack_b, size_stack);
	}
}
