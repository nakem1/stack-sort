/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:54:41 by lmurray           #+#    #+#             */
/*   Updated: 2021/03/14 22:13:18 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		check_last(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (!ft_isdigit(str[i - 1]))
		stop_program(1);
}

void		norm_fn(int *i, int *j, int *count, char *str)
{
	*i = 0;
	*j = 0;
	*count = 0;
	check_last(str);
	if (!ft_isdigit(str[0]))
		stop_program(1);
}

char		**parse_str(int *argc, char *str)
{
	int		i;
	int		j;
	int		count;
	char	**temp;

	norm_fn(&i, &j, &count, str);
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
		{
			if (++j > 1)
				stop_program(1);
			i++;
		}
		j = 0;
		i += ft_strlen_int(ft_atoi(&str[i]));
		count++;
	}
	if (str[i] == ' ')
		stop_program(1);
	*argc = count + 1;
	str = ft_strjoin("hello ", str);
	temp = ft_split(str, ' ');
	free(str);
	return (temp);
}
