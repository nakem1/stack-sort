/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:36:32 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/24 12:31:33 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	handle_rotate(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(str, "ra"))
		rotate(stack_a, NULL);
	else if (!ft_strcmp(str, "rb"))
		rotate(stack_b, NULL);
	else if (!ft_strcmp(str, "rr"))
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
	}
	else if (!ft_strcmp(str, "rra"))
		reverse_rotate(stack_a, NULL);
	else if (!ft_strcmp(str, "rrb"))
		reverse_rotate(stack_b, NULL);
	else if (!ft_strcmp(str, "rrr"))
	{
		reverse_rotate(stack_a, NULL);
		reverse_rotate(stack_b, NULL);
	}
	else
		stop_program(1);
}

void	set_command_tostack(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(str, "sa"))
		swap(stack_a, NULL);
	else if (!ft_strcmp(str, "sb"))
		swap(stack_b, NULL);
	else if (!ft_strcmp(str, "ss"))
	{
		swap(stack_a, NULL);
		swap(stack_b, NULL);
	}
	else if (!ft_strcmp(str, "pa"))
		push(stack_b, stack_a, NULL);
	else if (!ft_strcmp(str, "pb"))
		push(stack_a, stack_b, NULL);
	else
		handle_rotate(str, stack_a, stack_b);
}

void	checker(t_list **stack_a)
{
	int		log;
	char	*str;
	t_list	*stack_b;

	stack_b = NULL;
	while ((log = get_next_line(0, &str) > 0))
	{
		set_command_tostack(str, stack_a, &stack_b);
		free(str);
	}
	if (log == -1)
		stop_program(1);
	if (check_stack(*stack_a, stack_b))
		stop_program(2);
	else
		stop_program(0);
}
