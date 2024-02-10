/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/10 17:04:35 by art3mis          ###   ########.fr       */
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
	if (is_sign(str[i]) == true && str[i + 1])
		i++;
	else if (is_space(&str[i]) == true && str[i + 1])
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (false);
	return (true);
}

static t_bool	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && (nbr_in_str_cmp(argv[i], argv[j]) == 0))
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
	if (have_duplicates(argv) == true)
		return (false);
	while (argv[i])
	{
		if (!is_only_digit(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
