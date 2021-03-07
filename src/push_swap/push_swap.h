/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:56:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/07 01:43:05 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../operations/operations.h"
# include "../parse/parse.h"

void	handle_three_elem(t_list **stack);
void	handle_two_elem(t_list **stack_a);
void	more_three_elem(t_list **stack_a, t_list **stack_b, int size_stack);
void	stack_reduction(t_list **stack_a, t_list **stack_b, int *size_stack);
void		select_how_gotop(t_list **stack, int size_stack, int position);

#endif
