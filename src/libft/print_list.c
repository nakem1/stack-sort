/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:39:45 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 22:57:41 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft.h"

t_list	*norm1(t_list *list, t_list *list1)
{

}

void	print_list(t_list *list, t_list *list1)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("\n________________________________________\n");
	printf("|         A         ||        B        |\n");
	while(list || list1)
	{
		if (list && list1)
		{
			printf("|     [%d] = %d     ||     [%d] = %d     |\n", i++,
					(*(int *)(list->content)), j++, (*(int *)(list1->content)));
			list = list->next;
			list1 = list1->next;
		}
		else if (list)
		{
			printf("|     [%d] = %d     ||                   |\n", i++,
					(*(int *)(list->content)));
			list = list->next;
		}
		else if (list1)
		{
			printf("|                   ||     [%d] = %d     |\n",
					j++, (*(int *)(list1->content)));
		list1 = list1->next;
		}
	}
	printf("________________________________________\n\n\n");
}