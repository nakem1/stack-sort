/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:05:51 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/07 03:09:07 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		handle_two_elem(t_list **stack_a)
{
	if (check_stack(*stack_a, NULL))
		swap(stack_a, "sa\n");
}

void		handle_three_elem_utils(t_list **stack)
{
	if ((*(int *)((*stack)->content) <
			*(int *)((*stack)->next->next->content))
			&& (*(int *)((*stack)->next->next->content) < \
			*(int *)((*stack)->next->content)))
	{
		swap(stack, "sa\n");
		print_list(*stack, NULL);
		rotate(stack, "ra\n");
	}
	else if ((*(int *)((*stack)->content) < *(int *)((*stack)->next->content))
			&& (*(int *)((*stack)->next->next->content) < \
			*(int *)((*stack)->content)))
		reverse_rotate(stack, "rra\n");
	else
		ft_putstr_fd("kek trouble\n", 1);
}

void		handle_three_elem(t_list **stack)
{
	if ((*(int *)((*stack)->content) > *(int *)((*stack)->next->content)) && \
			(*(int *)((*stack)->next->next->content) > \
			*(int *)((*stack)->content)))
	{
		swap(stack, "sa");
		print_list(*stack, NULL);
	}
	else if ((*(int *)((*stack)->content) > *(int *)((*stack)->next->content))
			&& (*(int *)((*stack)->next->next->content) < \
			*(int *)((*stack)->next->content)))
	{
		swap(stack, "sa\n");
		print_list(*stack, NULL);
		reverse_rotate(stack, "rra\n");
		print_list(*stack, NULL);
	}
	else if ((*(int *)((*stack)->content) >
			*(int *)((*stack)->next->next->content))
			&& (*(int *)((*stack)->next->next->content) > \
			*(int *)((*stack)->next->content)))
	{
		rotate(stack, "ra\n");
		print_list(*stack, NULL);
	}
	else
	{
		handle_three_elem_utils(stack);
		print_list(*stack, NULL);
	}
}
