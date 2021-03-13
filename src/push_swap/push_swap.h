/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:56:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/13 06:16:34 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../operations/operations.h"
# include "../parse/parse.h"

# define A_STACK 1
# define B_STACK 2
# define PUSH 1
# define ROTATE 2
# define REV_ROTATE 3
# define TOP 1
# define BOTTOM 2
// # define PUSH_STACK(msg) ((msg) == 1 ? ("pb\n") : ("pa\n"))
// # define ROTATE_STACK(msg) ((msg) == 1 ? ("ra\n") : ("rb\n"))
// # define REV_ROTATE_STACK(msg) ((msg == 1 ? ("rra\n") : ("rrb\n")))

# define MIN 1
# define MAX 2

void	handle_three_elem(t_list **stack);
void	handle_two_elem(t_list **stack_a);
void	more_three_elem(t_list **stack_a, t_list **stack_b, int size_stack);
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
void	more_five_hundred_elem(t_list **stack_a, t_list **stack_b, int size_stack);
void	select_what_todo(t_list **stack_a, t_list **stack_b, int position);

#endif
