/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:12:25 by lmurray           #+#    #+#             */
/*   Updated: 2021/04/25 21:55:50 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	get_prompt(char *msg, int forground, int background)
{
		init_pair(1, forground, background); // define a forground, background pair
		attron(COLOR_PAIR(1));   // enable for/back ground color to use
		printw(msg); // print string to curses window
		attroff(COLOR_PAIR(1));
		printw("> ");
		refresh();  
}

void	handle_prompt(t_prompt *prompt)
{
	get_prompt(prompt->msg, prompt->forground, prompt->background);
	scanw("%s\n", prompt->command);
	if (!ft_strcmp(prompt->command, "q") || !ft_strcmp(prompt->command, "quit") || \
		!ft_strcmp(prompt->command, "exit") || prompt->exit)
	{
		prompt->exit = 1;
		return ;
	}
}

void	push_swap_cli(t_prompt *prompt)
{
	clear();
	prompt->msg = "push_swap";
	prompt->forground = COLOR_BLACK;
	prompt->background = COLOR_YELLOW;
	handle_prompt(prompt);
	if (prompt->exit == 1)
		return ;
}



int		main()
{
	t_prompt	*prompt;

	initscr();
	start_color();
	flag = 1;
	prompt->exit = 0;
	prompt = (t_prompt *)malloc(sizeof(t_prompt));
	prompt->msg = (char *)malloc(50);
	prompt->command = (char *)malloc(5000);
	while (1)
	{
		if (prompt->exit == 1)
		{
			endwin();
			return (0);
		}
		prompt->msg = "Mekan! ";
		prompt->forground = COLOR_RED;
		prompt->background = COLOR_CYAN;
		handle_prompt(prompt);
		if (!ft_strcmp(prompt->command, "push_swap"))
			push_swap_cli(prompt);
		// else if (prompt->command, "checker")
		// 	checker_cli(prompt);
	}
}
