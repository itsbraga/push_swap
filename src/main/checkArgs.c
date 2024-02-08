/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/08 21:29:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	isSign(char c)
{
	if (!(c == '-' || c == '+'))
		return (false);
	return (true);
}

static bool	isSpace(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		return (false);
	return (true);
}

static bool	IsOnlyDigit(char *str)
{
	int	i;

	i = 0;
	if (isSign(str[i]) && (str[i + 1]))
		i++;
	if (isSpace(&str[i]) && (str[i + 1]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (false);
	return (true);
}

bool	haveDuplicate(char **argv)
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

bool	globalCheckIsSuccess(char **argv)
{
	int	i;

	i = 1;
	if (haveDuplicate(argv) == true)
	{
		write(2, "Error\n", 6);
		return (false);
	}
	while (argv[i])
	{
		if (IsOnlyDigit(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
