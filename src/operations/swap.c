/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:15:10 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 22:41:08 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap(t_list **stack, char *msg)
{
	t_list *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		*stack = tmp;
		if (msg)
			ft_putstr_fd(msg, 1);
	}
	if (g_flag == 1)
		print_list(*stack, NULL);
}
