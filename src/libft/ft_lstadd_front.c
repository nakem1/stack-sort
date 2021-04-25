/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:31:31 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 15:20:15 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		void		ft_lstadd_front
**
** Description:		Adds the element ’new’ at the beginning of the list.
*/

void		ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (*lst)
	{
		tmp = new;
		tmp->next = *lst;
		*lst = tmp;
	}
	else
		*lst = new;
}
