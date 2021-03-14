/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_elems_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:40:07 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 22:09:39 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*get_str_operation(int action, int stack)
{
	if (stack == A_STACK)
	{
		if (action == PUSH)
			return ("pb\n");
		else if (action == ROTATE)
			return ("ra\n");
		else if (action == REV_ROTATE)
			return ("rra\n");
	}
	else
	{
		if (action == PUSH)
			return ("pa\n");
		else if (action == ROTATE)
			return ("rb\n");
		else if (action == REV_ROTATE)
			return ("rrb\n");
	}
	return ("ERORR");
}

void		select_how_gotop(t_list **stack, int size_stack, int position,
		int msg)
{
	int i;

	i = 0;
	if (size_stack != 1)
	{
		if (position <= (size_stack / 2))
		{
			while (i < position)
			{
				rotate(stack, get_str_operation(ROTATE, msg));
				i++;
			}
		}
		else
		{
			i = position;
			while (i < size_stack)
			{
				reverse_rotate(stack, get_str_operation(REV_ROTATE, msg));
				i++;
			}
		}
	}
}

int			check_one_flag(t_list **stack)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->flag)
			count++;
		tmp = tmp->next;
	}
	if (count == 1)
		return (1);
	return (0);
}

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
		int msg)
{
	int		flag_find;
	t_list	*tmp;

	set_position(stack1);
	flag_find = 0;
	if (!check_one_flag(stack1))
		find_min_dist(stack1, *size_stack);
	tmp = *stack1;
	while (flag_find != 1)
	{
		if (tmp->flag == 1)
		{
			if (msg == A_STACK)
			{
				select_what_todo(stack1, stack2, tmp->position);
				set_position(stack1);
			}
			select_how_gotop(stack1, *size_stack, tmp->position, msg);
			flag_find = 1;
		}
		tmp = tmp->next;
	}
	push(stack1, stack2, get_str_operation(PUSH, msg));
	*size_stack -= 1;
}
