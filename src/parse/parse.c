/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:55:49 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/11 04:51:49 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_stack(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL)
		return (1);
	while (stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}	
	return (0);
}

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

int		check_duplicate(int *digits, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (digits[i] == digits[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_overflow(int argc, char **argv)
{
	long	*digits_long;
	int		i;

	i = 1;
	if (!(digits_long = (long *)malloc(sizeof(long) * argc - 1)))
		return (1);
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (1);
		digits_long[i - 1] = ft_atoi_long(argv[i]);
		if (digits_long[i - 1] <= 2147483647 && digits_long[i - 1] >= -2147483648)
			i++;
		else
			return (1);
	}
	return (0);
}

int		*parse(int argc, char **argv)
{
	int		*digits;
	int		i;

	i = 1;
	if (check_overflow(argc, argv))
		return (NULL);
	if (!(digits = (int *)malloc(sizeof(int) * argc - 1)))
		return (NULL);
	while (i < argc)
	{
		if (!str_isdigits(argv[i]))
			return (NULL);
		digits[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (check_duplicate(digits, argc - 1))
		return (NULL);
	return (digits);
}
