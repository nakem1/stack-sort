/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:18:10 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 21:33:45 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
#define BONUS_H

# include "push_swap.h"
# include "checker.h"
// # include <stdio.h>
// # include <stdlib.h>
// # include <string.h>
// # include <readline/readline.h>
// # include <readline/history.h>
# include <ncurses.h>
# include "push_swap.h"
# include "checker.h"

typedef struct		s_prompt
{
	char			*msg;
	char			*command;
	int				forground;
	int				background;
	int				exit;
}					t_prompt;

#endif