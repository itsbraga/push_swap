/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/06 18:31:15 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	isSign(char c)
{
	if (!(c == '-' || c == '+'))
		return (false);
	return (true);
}

static bool	isSpace(char *argv)
{
	int	i;

	i = 0;
	if (!(argv[i] == 32 || (argv[i] >= 9 && argv[i] <= 13)))
		return (false);
	return (true);
}

static bool	IsOnlyDigit(char *argv)
{
	int	i;

	i = 1;
	if (isSign(argv[i]) && (argv[i + 1]))
		i++;
	if (isSpace(&argv[i]) && (argv[i + 1]))
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] && !ft_isdigit(argv[i]))
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
		j = 1;
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
		return (false);
	while (argv[i])
	{
		if (IsOnlyDigit(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}