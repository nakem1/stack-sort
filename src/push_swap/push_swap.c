/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:55:51 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 22:19:22 by lmurray          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int		*digits;
	t_list	*stack_a;

	if (argc > 1)
	{
		if (argc == 2)
			argv = parse_str(&argc, argv[1]);
		if (!(digits = parse(argc, argv)))
			stop_program(1);
		stack_a = get_stack(argc, digits);
		if (!check_stack(stack_a, NULL))
			return (0);
		push_swap(&stack_a);
		free(digits);
	}
	return (0);
}
