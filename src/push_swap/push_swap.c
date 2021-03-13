/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:55:51 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/13 07:45:24 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// norminette и сега
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
		else if (size_stack > 3 && size_stack < 100)
			more_three_elem(stack_a, &stack_b, size_stack);
		else if (size_stack >= 100 && size_stack < 500)
			more_hundred_elem(stack_a, &stack_b, size_stack);
		else if (size_stack >= 500)
			more_five_hundred_elem(stack_a, &stack_b, size_stack);
	}
}
// проверить дебаггером на малых числах алгоритм. И закончить проект
int		main(int argc, char **argv)
{
	int		*digits;
	t_list	*stack_a;

	if (argc > 1)
	{
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

// int 		main(void)
// {
// 	int		digits[500] = {3,64,87,37,13,89,102,76,2,90,103,12,11,95,53,69,70,33,52,21,18,9,62,48,57,75,41,36,85,34,86,23,26,61,31,100,65,17,50,66,98,88,19,97,29,5,101,96,60,93,38,99,71,73,4,74,25,84,63,72,54,44,40,1,43,92,7,15,39,51,22,68,28,79,94,8,24,20,67,45,35,81,14,58,56,91,77,16,49,27,55,78,30,42,59,83,32,46,82,47};
// 	t_list	*stack_a;

// 	stack_a = get_stack(101, digits);
// 	// free(digits);
// 	if (!check_stack(stack_a, NULL))
// 		return (0);
// 	push_swap(stack_a);
// 	return (0);
// }
