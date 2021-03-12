/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:14:20 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/11 22:32:49 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		reverse_rotate(t_list **stack, char *msg)
{
	t_list *tmp;
	t_list *tmp1;

	tmp = *stack;
	if (tmp && tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp1 = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(stack, tmp1);
		if (msg)
			ft_putstr_fd(msg, 1);
	}
}
