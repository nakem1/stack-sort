/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:32:39 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 22:40:51 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		rotate(t_list **stack, char *msg)
{
	t_list *tmp;

	tmp = *stack;
	if (tmp)
	{
		*stack = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
		if (msg)
			ft_putstr_fd(msg, 1);
	}
	if (g_flag == 1)
		print_list(*stack, NULL);
}
