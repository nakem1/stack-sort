/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 04:15:56 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/05 19:17:56 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			check_stack(t_list *stack_a, t_list *stack_b)
{
	int		*tmp;

	if (stack_b != NULL)
		return (1);
	tmp = (int *)stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (*tmp >= *((int *)stack_a->content))
			return (1);
		tmp = (int *)stack_a->content;
		stack_a = stack_a->next;
	}
	return (0);
}
