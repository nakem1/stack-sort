/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:43:59 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 15:20:03 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "operations.h"
# include "parse.h"

void		stop_program(int flag);
void		handle_rotate(char *str, t_list **stack_a, t_list **stack_b);
void		set_command_tostack(char *str, t_list **stack_a, t_list **stack_b);
void		checker(t_list **stack_a);

#endif
