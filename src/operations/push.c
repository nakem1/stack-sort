/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:42:04 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/11 06:56:16 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		push(t_list **src, t_list **dest, char *msg)
{
	t_list *tmp;

	tmp = *src;
	if (tmp)
	{
		*src = (*src)->next;
		tmp->next = NULL;
		ft_lstadd_front(dest, tmp);
		ft_putstr_fd(msg, 1);
	}
}
