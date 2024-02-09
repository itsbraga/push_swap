/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/09 22:19:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_bool	is_sign(char c)
{
	if (!(c == '-' || c == '+'))
		return (false);
	return (true);
}

static t_bool	is_space(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		return (false);
	return (true);
}

static t_bool	is_only_digit(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) == true && (str[i + 1]))
		i++;
	if (is_space(&str[i]) == true && (str[i + 1]))
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (false);
	return (true);
}

t_bool	have_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (j != i && (ft_strcmp(argv[i], argv[j]) == 0))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

t_bool	global_check_successful(char **argv)
{
	int	i;

	i = 1;
	if (have_duplicate(argv) == true)
		return (false);
	while (argv[i])
	{
		if (is_only_digit(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
