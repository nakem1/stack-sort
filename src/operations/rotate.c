/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:32:39 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/07 03:03:13 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		rotate(t_list **stack, char *msg)
{
	t_list *tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	if (msg)
		ft_putstr_fd(msg, 1);
}

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	int		arr[5] = {1,2,3,4,5};
// 	int		arr1[5] = {5,4,3,2,1};

// 	a = NULL;
// 	b = NULL;

// 	ft_list_push_back(&a, &arr[0]);
// 	ft_list_push_back(&a, &arr[1]);
// 	ft_list_push_back(&a, &arr[2]);
// 	ft_list_push_back(&a, &arr[3]);
// 	ft_list_push_back(&a, &arr[4]);

// 	ft_list_push_back(&b, &arr1[0]);
// 	ft_list_push_back(&b, &arr1[1]);
// 	ft_list_push_back(&b, &arr1[2]);
// 	ft_list_push_back(&b, &arr1[3]);
// 	ft_list_push_back(&b, &arr1[4]);
// 	print_list(a);
// 	rotate(&a);
// 	print_list(a);
// }
