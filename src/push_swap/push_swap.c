/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:55:51 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/07 22:54:13 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *stack_a)
{
	t_list	*stack_b;
	int		size_stack;

	stack_b = NULL;
	size_stack = ft_lstsize(stack_a);
	print_list(stack_a, NULL);
	if (size_stack > 1)
	{
		if (size_stack == 2)
			handle_two_elem(&stack_a);
		else if (size_stack == 3)
			handle_three_elem(&stack_a);
		else if (size_stack > 3 && size_stack < 100)
			more_three_elem(&stack_a, &stack_b, size_stack);
		// else if (size_stack >= 100 && size_stack < 500)
		// 	more_hundred_elem(stack_a, stack_b);
		// else if (size_stack >= 500);
		// 	more_five_hundred_elem(stack_a, stack_b);
	}
}

int		main(int argc, char **argv)
{
	int		*digits;
	t_list	*stack_a;

	if (argc > 1)
	{
		if (!(digits = parse(argc, argv)))
			stop_program(1);
		stack_a = get_stack(argc, digits);
		push_swap(stack_a);
	}
}
