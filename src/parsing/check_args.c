/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/17 19:31:52 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_sign(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (false);
	if (!(argv[i] == '-'))
		return (false);
	return (true);
}

bool	arg_isdigit(char *argv)
{
	int i;

	i = 0;
	if (is_sign(argv[i]) && (argv[i + 1] != '\0'))
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] && !ft_isdigit(argv[i]))
		return (false);
	return (true);
}

bool	is_duplicate(char **argv);