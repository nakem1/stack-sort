/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:56:42 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 22:09:13 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../libft/libft.h"

int			*parse(int argc, char **argv);
char		**parse_str(int *argc, char *str);
void		stop_program(int flag);
int			check_stack(t_list *stack_a, t_list *stack_b);

#endif
