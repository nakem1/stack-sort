/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:05:51 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/09 18:31:35 by lmurray          ###   ########.fr       */
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
		// print_list(*stack, NULL);
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
		// print_list(*stack, NULL);
	}
	else if ((*(int *)((*stack)->content) > *(int *)((*stack)->next->content))
			&& (*(int *)((*stack)->next->next->content) < \
			*(int *)((*stack)->next->content)))
	{
		swap(stack, "sa\n");
		// print_list(*stack, NULL);
		reverse_rotate(stack, "rra\n");
		// print_list(*stack, NULL);
	}
	else if ((*(int *)((*stack)->content) >
			*(int *)((*stack)->next->next->content))
			&& (*(int *)((*stack)->next->next->content) > \
			*(int *)((*stack)->next->content)))
	{
		rotate(stack, "ra\n");
		// print_list(*stack, NULL);
	}
	else
	{
		handle_three_elem_utils(stack);
		// print_list(*stack, NULL);
	}
}
