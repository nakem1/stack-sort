/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:05:51 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/11 15:00:27 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		handle_two_elem(t_list **stack_a)
{
	int		*data;
	t_list	*tmp;

	data = (int *)(*stack_a)->content;
	tmp = (*stack_a)->next;
	while (stack_a)
	{
		if (*data >= *((int *)tmp->content))
		{
			swap(stack_a, "sa\n");
			return ;
		}
		data = (int *)tmp->content;
		tmp = tmp->next;
	}
}

void		handle_three_elem_utils(t_list **stack)
{
	if ((*(int *)((*stack)->content) <
			*(int *)((*stack)->next->next->content))
			&& (*(int *)((*stack)->next->next->content) < \
			*(int *)((*stack)->next->content)))
	{
		swap(stack, "sa\n");
		rotate(stack, "ra\n");
	}
	else if ((*(int *)((*stack)->content) < *(int *)((*stack)->next->content))
			&& (*(int *)((*stack)->next->next->content) < \
			*(int *)((*stack)->content)))
		reverse_rotate(stack, "rra\n");
}

void		handle_three_elem(t_list **stack)
{
	if ((*(int *)((*stack)->content) > *(int *)((*stack)->next->content)) && \
			(*(int *)((*stack)->next->next->content) > \
			*(int *)((*stack)->content)))
	{
		swap(stack, "sa\n");
	}
	else if ((*(int *)((*stack)->content) > *(int *)((*stack)->next->content))
			&& (*(int *)((*stack)->next->next->content) < \
			*(int *)((*stack)->next->content)))
	{
		swap(stack, "sa\n");
		reverse_rotate(stack, "rra\n");
	}
	else if ((*(int *)((*stack)->content) >
			*(int *)((*stack)->next->next->content))
			&& (*(int *)((*stack)->next->next->content) > \
			*(int *)((*stack)->next->content)))
	{
		rotate(stack, "ra\n");
	}
	else
		handle_three_elem_utils(stack);
}
