/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:14:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/09 19:34:37 by lmurray          ###   ########.fr       */
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

void		find_optimal(int *heaps, t_list **stack_a)
{
	static int		var;
	t_list		*tmp;
	t_list		*max;
	int			i;
	int			j;

	printf("____________STATIC___________ = %d\n", var);
	var++;
	i = 0;
	max = NULL;
	while (i < 5)
	{
		j = 0;
		tmp = *stack_a;
		find_optimal_min(heaps, i, stack_a);
		while (tmp)
		{
			if (tmp->index >= heaps[i] && tmp->index < heaps[i + 1])
				max = tmp;
			tmp = tmp->next;
			j++;
		}
		if (max != NULL)
		{
			max->flag = 1;
			return ;
		}
		i++;
	}
}

// int	main(void)
// {
// 	t_list	*a;
// 	int		arr[99] = {17,93,80,99,56,5,51,84,4,57,48,14,29,55,35,74,21,94,60,68,63,1,92,23,82,12,67,69,98,52,19,83,97,78,39,75,100,25,24,8,7,41,11,86,44,36,72,18,73,16,64,47,90,65,87,77,59,61,45,30,53,54,66,76,28,37,95,70,91,27,6,50,43,81,3,46,13,31,89,88,96,38,62,33,10,15,79,20,42,40,85,26,34,71,49,32,22,58,2};
// 	int		*heaps;
// 	int		i;
// 	t_list	*tmp;

// 	a = NULL;
// 	i = 0;
// 	while (i < 99)
// 	{
// 		ft_list_push_back(&a, &arr[i]);
// 		i++;
// 	}
// 	set_index(&a, 99);
// 	reset_flag(&a);;
// 	tmp = a;
// 	i = 0;
// 	while (tmp)
// 	{
// 		printf("%d index is [%d]\n", i, tmp->index);
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	heaps = get_heaps(99);
// 	find_optimal(heaps, &a);
// 	tmp = a;
// 	i = 0;
// 	while (tmp)
// 	{
// 		printf("%d = [%d]\n", i, tmp->flag);
// 		tmp = tmp->next;
// 		i++;
// 	}
// }
