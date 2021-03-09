/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_elems_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:40:07 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/09 20:28:06 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		select_how_gotop(t_list **stack, int size_stack, int position)
{
	int i;

	i = 0;
	if (position < (size_stack / 2))
	{
		while (i < position)
		{
			rotate(stack, "ra\n");
			// print_list(*stack, NULL);
			i++;
		}
	}
	else
	{
		i = position;
		while (i < size_stack)
		{
			reverse_rotate(stack, "rra\n");
			// print_list(*stack, NULL);
			i++;
		}
	}
}
// когда один флаг, то зануляет его
void		find_min_dist(t_list **stack, int size_stack)
{
	int		i[2];
	int		j;
	int		k;
	t_list	*tmp;

	j = 0;
	k = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->flag == 1)
			i[j++] = k;
		k++;
		tmp = tmp->next;
	}
	if (i[0] <= (size_stack - i[1]))
	{
		tmp = ft_list_at(*stack, i[1]);
		tmp->flag = 0;
	}
	else
	{
		tmp = ft_list_at(*stack, i[0]);
		tmp->flag = 0;
	}
}

void		stack_reduction(t_list **stack1, t_list **stack2, int *size_stack,
		char *msg)
{
	int		i;
	int		flag_find;
	t_list	*tmp;
	t_list	*temp;

	i = 0;
	flag_find = 0;
	find_min_dist(stack1, *size_stack);
	tmp = *stack1;
	temp = *stack1;
	while (temp)
	{
		printf("%d = [%d]\n", *(int *)temp->content, temp->flag);
		temp = temp->next;
	}
	print_list(*stack1, *stack2);
	while (flag_find != 1)
	{
		if (tmp->flag == 1)
		{
			select_how_gotop(stack1, *size_stack, i);
			flag_find = 1;
		}
		i++;
		tmp = tmp->next;
	}
	push(stack1, stack2, msg);
	// print_list(*stack1, *stack2);
	*size_stack -= 1;
}
