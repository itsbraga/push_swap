/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/24 19:31:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	is_sign(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (false);
	if (!(argv[i] == '-' || argv[i] == '+'))
		return (false);
	return (true);
}

static bool	arg_isdigit(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && (argv[i + 1]))
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] && !ft_isdigit(argv[i]))
		return (false);
	return (true);
}

static bool	is_duplicate(char **argv)
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

/*	Appelle toutes les fonctions precedentes pour un check global des
	arguments passes en parametres
*/
bool	globalCheck(char **argv);