/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:14:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 04:51:47 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_optimal_min(int *heaps, int i, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > heaps[i] && tmp->index < heaps[i + 1])
		{
			tmp->flag = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void		find_optimal(int *heaps, int size_heaps, t_list **stack_a)
{
	t_list		*tmp;
	t_list		*max;
	int			i;

	i = 0;
	max = NULL;
	while (i < size_heaps)
	{
		tmp = *stack_a;
		find_optimal_min(heaps, i, stack_a);
		while (tmp)
		{
			if (tmp->index >= heaps[i] && tmp->index < heaps[i + 1])
				max = tmp;
			tmp = tmp->next;
		}
		if (max != NULL)
		{
			max->flag = 1;
			return ;
		}
		i++;
	}
}
