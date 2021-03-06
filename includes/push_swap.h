/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:56:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 16:14:31 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"
# include "parse.h"

# define A_STACK 1
# define B_STACK 2
# define PUSH 1
# define ROTATE 2
# define REV_ROTATE 3
# define TOP 1
# define BOTTOM 2

# define MIN 1
# define MAX 2

void	handle_three_elem(t_list **stack);
void	handle_two_elem(t_list **stack_a);
void	more_three_elem(t_list **stack_a, t_list **stack_b, int size_stack);
void	more_six_elems(t_list **stack_a, t_list **stack_b, int size_stack);
void	stack_reduction(t_list **stack_a, t_list **stack_b, int *size_stack,
		int msg);
void	stack_reduction_b(t_list **stack_a, t_list **stack_b, int *size_stack,
		int msg);
void	find_min_dist(t_list **stack, int size_stack);
void	select_how_gotop(t_list **stack, int size_stack, int position, int msg);
void	set_index(t_list **stack_a, int size_stack);
int		*get_heaps(int size_stack, int size_heaps);
void	reset_flag(t_list **stack);
void	find_optimal(int *heaps, int size_heaps, t_list **stack_a);
void	find_minmax(t_list **stack, int minmax);
void	more_hundred_elem(t_list **stack_a, t_list **stack_b, int size_stack);
void	more_five_hundred_elem(t_list **stack_a, t_list **stack_b,
		int size_stack);
void	select_what_todo(t_list **stack_a, t_list **stack_b, int position);
void	set_position(t_list **stack);
void	botmove_stack_b(t_list **stack_b, int position, int steps,
		int direction);
void	topmove_stack_b(t_list **stack_b, int position, int steps,
		int direction);
void	push_swap(t_list **stack_a);

#endif
