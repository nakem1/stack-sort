/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:34:29 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 15:05:27 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"

void		swap(t_list **stack, char *msg);
void		push(t_list **src, t_list **dest, char *msg);
void		rotate(t_list **stack, char *msg);
void		reverse_rotate(t_list **stack, char *msg);

#endif
