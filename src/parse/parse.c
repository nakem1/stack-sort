/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:55:49 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/05 18:03:50 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	stop_program(int flag)
{
	if (flag == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (flag == 2)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	exit(0);
}

int		*parse(int argc, char **argv)
{
	int		*digits;
	int		i;

	i = 1;
	if (!(digits = (int *)malloc(sizeof(int) * argc - 1)))
		return (NULL);
	while (i < argc)
	{
		if (!str_isdigits(argv[i]))
			return (NULL);
		digits[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (digits);
}
